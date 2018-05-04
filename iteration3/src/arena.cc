/**
 * @file arena.cc
 *
 * @copyright 2017 3081 Staff, All rights reserved.
 */

/*******************************************************************************
 * Includes
 ******************************************************************************/
#include <algorithm>

#include "src/arena.h"
#include "src/arena_params.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);

/*******************************************************************************
 * Constructors/Destructor
 ******************************************************************************/
Arena::Arena(const struct arena_params *const params) :
    x_dim_(params->x_dim),
    y_dim_(params->y_dim),
    n_robots_(static_cast<unsigned int>(params -> n_robots)),
    n_players_(1),
    n_obstacles_(static_cast<unsigned int>(params->n_obstacles)),
    player_(new Player(&params->player)),  // initial lize player
    recharge_station_(new RechargeStation(params->recharge_station.radius,
                                          params->recharge_station.pos,
                                          params->recharge_station.color)),
    home_base_(new HomeBase(&params->home_base)),
    robot_(),
    robots_(),
    entities_(),
    mobile_entities_(),
    win_(0),
    lose_(0) {
  entities_.push_back(player_);
  mobile_entities_.push_back(player_);

  entities_.push_back(recharge_station_);

  entities_.push_back(home_base_);
  mobile_entities_.push_back(home_base_);

  // entities_.push_back(super_bot_);
  // mobile_entities_.push_back(super_bot_);

  for (size_t i = 0; i < n_obstacles_; ++i) {
    entities_.push_back(new Obstacle(
        params->obstacles[i].radius,
        params->obstacles[i].pos,
        params->obstacles[i].color));
  } /* for(i..) */
/************************** 11/28 **********************/
  for (size_t i = 0; i < n_robots_; ++i) {
    robot_ = new Robot(&params->robots[i]);
    entities_.push_back(robot_);
    mobile_entities_.push_back(robot_);
    robots_.push_back(robot_);
  }
/*******************************************************/
}

Arena::~Arena() {
  for (auto ent : entities_) {
    delete ent;
  } /* for(ent..) */
}
/*******************************************************************************
 * Member Functions
 ******************************************************************************/
void Arena::Reset() {
  for (auto ent : entities_) {
    ent->Reset();
  } /* for(ent..) */
} /* reset() */

std::vector<Obstacle *> Arena::obstacles() {
  std::vector<Obstacle *> res;
  for (auto ent : entities_) {
    auto *o = dynamic_cast<Obstacle *>(ent);
    if (o) {
      res.push_back(o);
    }
  } /* for(ent..) */
  return res;
} /* robots() */
/*********** 11/28 ********************/
std::vector<Robot*> Arena::robots() {
  std::vector<Robot*> res;
  for (auto ent : mobile_entities_) {
    auto* o = dynamic_cast<Robot*>(ent);
    if (o) {
      res.push_back(o);
    }
  } /* for(ent..) */
  return res;
} /* robots() */
/***************************************/
void Arena::AdvanceTime(double dt) {
  if (dt == 0)
    return;
  for (size_t i = 0; i < 1; ++i) {
    UpdateEntitiesTimestep();
  } /* for(i..) */
} /* AdvanceTime() */

void Arena::UpdateEntitiesTimestep() {
  /*
   * First, update the position of all entities, according to their current
   * velocities.
   */
  for (auto ent : entities_) {
    ent->TimestepUpdate(1);
  } /* for(ent..) */
// robot has run out of battery
//   */
/*****************************************************************************/
  if (player_->battery_level() <= 0) {
    Reset();
    lose_ += 1;
  }  // battery for player
/****************************************************************************/
  /*
   * Next, check if the robot has collided with the recharge station or the home
   * base. These need to be before the general collisions, which can move the
   * robot away from these "obstacles" before the "collisions" have been
   * properly processed.
   */

  EventCollision ec;
  // EventEntityType et;

  int frozen_robots = 0;
  int super_robots = 0;

  /* check win */
    for (uint j = 0; j < n_robots_; j++) {
      if (robots_[j]->get_speed() == 0) {
        frozen_robots++;
      }

      if (frozen_robots == 5) {
        win_ += 1;
        Reset();
      }

      if (robots_[j]->get_super()) {
        super_robots++;
      }

      if (super_robots == 5) {
        lose_ += 1;
        Reset();
      }
    }
  /* */
  for (uint i = 0; i < n_obstacles_; i++) {
    CheckForEntityCollision(player_, obstacles()[i], &ec,
                            player_->collision_delta());

    if (ec.collided()) {
      player_->Accept(&ec);

      if (obstacles()[i] == recharge_station_) {
        EventRecharge er;
        player_->Accept(&er);
      }
    }
  }

/***************************************************************************/
for (uint i = 0; i < n_robots_; i++) {
  CheckForEntityCollision(home_base_, robots()[i], &ec,
                          home_base_->collision_delta());

  if (ec.collided()) {
    robots_[i]-> set_super(true);
    robots_[i]-> set_color(csci3081::Color(255, 0, 0, 255));
  }
}
/***************************************************************************/

/************************* player collied robot ****************************/
  for (uint i = 0; i < n_robots_; i++) {
    CheckForEntityCollision(player_, robots()[i], &ec,
                            player_->collision_delta());

    if (ec.collided()) {
      player_->Accept(&ec);
      if (robots_[i]->get_super() == false) {
        robots_[i]-> set_speed(0);
      } else {
        player_->is_freeze();
      }
    }
  }

  for (uint x = 0; x < n_robots_; x++) {
  uint y = 0;
  while (y < n_robots_) {
    if (x == y && x!= n_robots_-1) {
      y++;
      CheckForEntityCollision(robots()[x], robots()[y], &ec,
                              robots()[y]->collision_delta());

      if (ec.collided()) {
        robots_[x]-> set_speed(5);
        robots_[y]-> set_speed(5);
      }
      y++;
      continue;
    }
    if (x != y) {
      CheckForEntityCollision(robots()[x], robots()[y], &ec,
                              robots()[y]->collision_delta());

      if (ec.collided()) {
        robots_[y]-> set_speed(5);
        robots_[x]-> set_speed(5);
      }
      y++;
    }
    if (x == y && x == n_robots_-1) {
      break;
    }
  }
}
/****************************************************************************/
  /*
   * Finally, some pairs of entities may now be close enough to be considered
   * colliding, send collision events as necessary.
   *
   * When something collides with an immobile entity, the immobile entity does
   * not move (duh), so no need to send it a collision event.
   */
  for (auto ent : mobile_entities_) {
    // Check if it is out of bounds. If so, use that as point of contact.
    CheckForEntityOutOfBounds(ent, &ec);

    // If not at wall, check if colliding with any other entities (not itself)
    if (!ec.collided()) {
      for (size_t i = 0; i < entities_.size(); ++i) {
        if (entities_[i] == ent) {
          continue;
        }
        CheckForEntityCollision(ent, entities_[i], &ec, ent->collision_delta());
        if (ec.collided()) {
          ent->Accept(&ec);
// **************************************************************************
          if ((ent == player_) && (entities_[i] == recharge_station_)) {
            EventRecharge er;
            player_->Accept(&er);
          }
//*****************************************************************************
          break;
        }
      } /* for(i..) */
    } /* else */
    ent->Accept(&ec);
  } /* for(ent..) */
} /* UpdateEntities() */

void Arena::CheckForEntityOutOfBounds(const ArenaMobileEntity *const ent,
                                      EventCollision *const event) {
  if (ent->get_pos().x() + ent->get_radius() >= x_dim_) {
    // Right Wall
    event->collided(true);
    event->point_of_contact(Position(x_dim_, ent->get_pos().y()));
    event->angle_of_contact(ent->get_heading_angle() - 180.0);  // int->double
  } else if (ent->get_pos().x() - ent->get_radius() <= 0) {
    // Left Wall
    event->collided(true);
    event->point_of_contact(Position(0, ent->get_pos().y()));
    event->angle_of_contact(ent->get_heading_angle() - 180.0);  // int->double
  } else if (ent->get_pos().y() + ent->get_radius() >= y_dim_) {
    // Bottom Wall
    event->collided(true);
    event->point_of_contact(Position(ent->get_pos().x(), y_dim_));
    event->angle_of_contact(ent->get_heading_angle());
  } else if (ent->get_pos().y() - ent->get_radius() <= 0) {
    // Top Wall
    event->collided(true);
    event->point_of_contact(Position(0, y_dim_));
    event->angle_of_contact(ent->get_heading_angle());
  } else {
    event->collided(false);
  }
} /* entity_out_of_bounds() */

double Arena::Distance(Position p1, Position p2) {
  double ent1_x = p1.x();
  double ent1_y = p1.y();
  double ent2_x = p2.x();
  double ent2_y = p2.y();

  double dist = std::sqrt(
    std::pow(ent2_x - ent1_x, 2) + std::pow(ent2_y - ent1_y, 2));

  return dist;
}  // refactor 1

void Arena::CheckForEntityCollision(const ArenaEntity *const ent1,
                                    const ArenaEntity *const ent2,
                                    EventCollision *const event,
                                    double collision_delta) {
  /* Note: this assumes circular entities */
  double ent1_x = ent1->get_pos().x();
  double ent1_y = ent1->get_pos().y();
  double ent2_x = ent2->get_pos().x();
  double ent2_y = ent2->get_pos().y();
  if (Distance(ent1->get_pos(), ent2->get_pos()) >
      ent1->get_radius() + ent2->get_radius() + collision_delta) {
    event->collided(false);
  } else {
    // Populate the collision event.
    // Collided is true
    // Point of contact is point along perimeter of ent1
    // Angle of contact is angle to that point of contact
    // ref: https://stackoverflow.com/a/1736741
    event->collided(true);

    double angle = std::asin(std::abs(ent2_x - ent1_x) /
      Distance(ent1->get_pos(), ent2->get_pos()));

    if ((ent2_x - ent1_x) > 0) {
      if ((ent2_y - ent1_y) > 0) {
        // lower right
        event->point_of_contact(
            {
                ent1_x + std::sin(angle) * ent1->get_radius(),
                ent1_y + std::cos(angle) * ent1->get_radius()
            });
        angle = M_PI_2 - angle;
      } else if ((ent2_y - ent1_y) < 0) {
        // upper right
        event->point_of_contact(
            {
                ent1_x + std::sin(angle) * ent1->get_radius(),
                ent1_y - std::cos(angle) * ent1->get_radius()
            });
        angle += (3.0 * M_PI_2);  // int->double
      } else {  // if ((ent2_y - ent1_y) == 0)
        // 0 or 360 deg
        event->point_of_contact(
            {
                ent1_x + ent1->get_radius(),
                ent1_y
            });
        angle = 0;
      }
    } else if ((ent2_x - ent1_x) < 0)  {
      if ((ent2_y - ent1_y) > 0) {
        // lower left
        event->point_of_contact(
            {
                ent1_x - std::sin(angle) * ent1->get_radius(),
                ent1_y + std::cos(angle) * ent1->get_radius()
            });
        angle += M_PI_2;
      } else if ((ent2_y - ent1_y) < 0) {
        // upper left
        event->point_of_contact(
            {
                ent1_x - std::sin(angle) * ent1->get_radius(),
                ent1_y - std::cos(angle) * ent1->get_radius()
            });
        angle = (M_PI_2 * 2.0) + (M_PI_2 - angle);  // int->double
      } else {  // if ((ent2_y - ent1_y) == 0)
        // 180 deg
        event->point_of_contact(
            {
                ent1_x - ent1->get_radius(),
                ent1_y
            });
        angle = M_PI;
      }
    } else {  // if ((ent2_x - ent1_x) == 0)
      if ((ent2_y - ent1_y) > 0) {
        // 90 deg
        event->point_of_contact(
            {
                ent1_x,
                ent1_y + ent1->get_radius()
            });
        angle = M_PI_2;
      } else if ((ent2_y - ent1_y) < 0) {
        // 270 deg
        event->point_of_contact(
            {
                ent1_x,
                ent1_y - ent1->get_radius()
            });
        angle = (3.0 * M_PI_2);  // int->double
      } else {
        // completely overlap, which is theoretically impossible...
        std::cerr << ent1->get_name() << " is in complete overlap with "
                  << ent2->get_name() << ".\n";
        assert(false);
      }
    }

    event->angle_of_contact((M_PI - angle) / M_PI * 180.0);  // int->double
  }
} /* entities_have_collided() */

void Arena::Accept(const EventKeypress *const e) {
  // don't handle unsupported keys
  if (e->GetCmd() != COM_UNKNOWN)
    player_->Accept(new EventCommand(e->GetCmd()));
} /* Accept */

NAMESPACE_END(csci3081);
