
/* STUDENTS: Write your own unit tests in this file.  Or, better yet,
   rename this file to something more meaningful and/or add additional
   files of tests to this directory to test your project code in
   whatever ways you see fit!
 */

#ifndef STUDENT_UNIT_TESTS
#define STUDENT_UNIT_TESTS

// The Google Test framework
#include <gtest/gtest.h>


// Includes for project code in the ../src directory
#include "../src/arena.h"
#include "../src/proximity_sensor.h"
#include "../src/contact_sensor.h"
#include "../src/distress_call_sensor.h"
#include "../src/entity_type_sensor.h"
#include "../src/sensor_touch.h"  // sensor_touch test
#include "../src/sensor.h"

/*******************************************************************************
 * Namespaces
 ******************************************************************************/
NAMESPACE_BEGIN(csci3081);
/*******************************************************************************
 * Tests
 ******************************************************************************/
/*******************************************************************************
 * Sensor Touch Tests
 ******************************************************************************/
 TEST(SensorTouch, Sanity) {
   SensorTouch st;

   bool val = std::is_base_of<csci3081::Sensor, csci3081::SensorTouch>::value;
   EXPECT_TRUE(val);

   EXPECT_EQ(st.activated(), false);
   EXPECT_EQ(st.point_of_contact(), csci3081::Position(0, 0));
   EXPECT_EQ(st.angle_of_contact(), 0.0);

   st.activated(true);
   st.point_of_contact(csci3081::Position(1.0, 1.0));
   EXPECT_EQ(st.activated(), true);
   EXPECT_EQ(st.point_of_contact(), csci3081::Position(1.0, 1.0));
 }
 // Constructor test for Sensor Touch.

 TEST(SensorTouch, Reset) {
   csci3081::SensorTouch st;

   st.activated(true);
   st.point_of_contact(csci3081::Position(1.0, 1.0));
   EXPECT_EQ(st.activated(), true);
   EXPECT_EQ(st.point_of_contact(), csci3081::Position(1.0, 1.0));
   EXPECT_DOUBLE_EQ(st.angle_of_contact(), 45.0);

   st.Reset();
   EXPECT_EQ(st.angle_of_contact(), 0.0);
   EXPECT_EQ(st.point_of_contact(), csci3081::Position(0, 0));
   EXPECT_EQ(st.activated(), false);
 }
 // Function test for  Sensor touch.

 /*******************************************************************************
  * Sensor Touch Tests
  ******************************************************************************/
 /*******************************************************************************
  * Contact Sensor Tests
  ******************************************************************************/

TEST(Contact_Sensor, Constructor) {
  ContactSensor CS;

  bool val = std::is_base_of<csci3081::Sensor, csci3081::ContactSensor>::value;
  EXPECT_TRUE(val);

  // EXPECT_STREQ(CS.get_name(), "Contact sensor.");
  EXPECT_EQ(CS.point_of_contact(), csci3081::Position(0,0));
  EXPECT_EQ(CS.angle_of_contact(), 0.0);
}
// Constructor test for Contact Sensor

TEST(Contact_Sensor, setterandgetter) {
   ContactSensor cs;

   cs.activated(true);
   cs.point_of_contact(csci3081::Position(1.0, 1.0));
   EXPECT_EQ(cs.activated(), true);
   EXPECT_EQ(cs.point_of_contact(), csci3081::Position(1.0, 1.0));
   EXPECT_DOUBLE_EQ(cs.angle_of_contact(), 45.0);

   cs.activated(true);
   cs.point_of_contact(csci3081::Position(2.0, 2.0));
   EXPECT_EQ(cs.activated(), true);
   EXPECT_EQ(cs.point_of_contact(), csci3081::Position(2.0, 2.0));
   EXPECT_DOUBLE_EQ(cs.angle_of_contact(), 45.0);

   cs.activated(true);
   cs.angle_of_contact(30.0);
   EXPECT_EQ(cs.activated(), true);
   EXPECT_DOUBLE_EQ(cs.angle_of_contact(), 30.0);
 }
 // setter and getter function test for Contact Sensor.

 TEST(Contact_Sensor, accept) {
    ContactSensor cs;
    EventCollision e;

    cs.activated(true);
    e.point_of_contact(csci3081::Position(10.0, 20.0));
    e.angle_of_contact(30.0);

    cs.Accept(&e);
    EXPECT_EQ(cs.activated(), true);
    EXPECT_EQ(cs.point_of_contact(), csci3081::Position(10.0, 20.0));
    EXPECT_DOUBLE_EQ(cs.angle_of_contact(), 30.0);
}

 TEST(Contact_Sensor, Reset) {
    ContactSensor cs;

    cs.activated(true);
    cs.angle_of_contact(30.0);
    cs.point_of_contact(csci3081::Position(2.0, 2.0));
    EXPECT_EQ(cs.activated(), true);
    EXPECT_EQ(cs.point_of_contact(), csci3081::Position(2.0, 2.0));
    EXPECT_DOUBLE_EQ(cs.angle_of_contact(), 30.0);

    cs.Reset();

    EXPECT_EQ(cs.angle_of_contact(), 0.0);
    EXPECT_EQ(cs.point_of_contact(), csci3081::Position(0, 0));
    EXPECT_EQ(cs.activated(), false);

}
// Reset function test for COntact Sensor.

 /*******************************************************************************
  * Contact Sensor Tests
  ******************************************************************************/
 /*******************************************************************************
  * Distress Call Sensor Tests
  ******************************************************************************/

TEST(Distress_Call_Sensor, Constructor) {
  DistressCallSensor DCS;

  bool val = std::is_base_of<csci3081::Sensor, csci3081::DistressCallSensor>::value;
  EXPECT_TRUE(val);

  // EXPECT_STREQ(DCS.get_name(), "Distress call sensor.");
  EXPECT_EQ(DCS.activated(), false);
  EXPECT_EQ(DCS.get_detect_range(), 200.0);
}
// Distress Call Sensor Constructor test.

TEST(Distress_Call_Sensor, setterandgetter) {
  DistressCallSensor dcs;

  dcs.activated(true);
  dcs.set_detect_range(300.0);
  EXPECT_EQ(dcs.activated(), true);
  EXPECT_EQ(dcs.get_detect_range(), 300.0);
}
// Distress Call Sensor setter and getter test.

// TEST(Distress_Call_Sensor, accept) {
//   DistressCallSensor dcs;
//   EventDistressCall e;
//
//   e.distance(30.0);
//   EXPECT_EQ(e.get_distance(), 30.0);
//   dcs.Accept(&e);
//   EXPECT_EQ(dcs.activated(), true);
//
//   e.distance(210.0);
//   EXPECT_EQ(e.get_distance(), 210.0);
//   dcs.Accept(&e);
//   EXPECT_EQ(dcs.activated(), false);
// }
// Distress Call Sensor accept function test


TEST(Distress_Call_Sensor, Reset){
  DistressCallSensor dcs;

  dcs.activated(true);
  dcs.set_detect_range(300.0);
  EXPECT_EQ(dcs.activated(), true);
  EXPECT_EQ(dcs.get_detect_range(), 300.0);

  dcs.Reset();

  EXPECT_EQ(dcs.activated(), false);
  EXPECT_EQ(dcs.get_detect_range(), 200.0);
}
// Distress Call Sensor Reset() function test.

/*******************************************************************************
 * Distress Call Sensor Tests
 ******************************************************************************/
 /*******************************************************************************
  * Entity Type Sensor Tests
  ******************************************************************************/

TEST(Entity_Type_Sensor, Constructor) {
  EntityTypeSensor ETS;

  bool val = std::is_base_of<csci3081::Sensor, csci3081::EntityTypeSensor>::value;
  EXPECT_TRUE(val);

  // EXPECT_STREQ(ETS.get_name(), "Entity type sensor.");
  EXPECT_EQ(ETS.activated(),false);
  EXPECT_EQ(ETS.get_detect_range(), 50.0);
  EXPECT_EQ(ETS.get_Entity_Type(), NULL);


}
TEST(Entity_Type_Sensor, setterandgetter) {
  EntityTypeSensor ets;

  ets.activated(true);
  ets.set_detect_range(200.0);

  EXPECT_EQ(ets.get_detect_range(), 200.0);
  EXPECT_EQ(ets.activated(), true);
}
// Entity Type Sensor setter and getter's test

TEST(Entity_Type_Sensor, accepttype) {
  EntityTypeSensor ets;

  ets.Accept(kWall);
  EXPECT_EQ(ets.get_Entity_Type(), kWall);
  EXPECT_EQ(ets.activated(), false);

  ets.Accept(kRobot);
  EXPECT_EQ(ets.get_Entity_Type(), kRobot);
  EXPECT_EQ(ets.activated(), true);

  ets.Accept(kSuperBot);
  EXPECT_EQ(ets.get_Entity_Type(), kSuperBot);
  EXPECT_EQ(ets.activated(), true);

  ets.Accept(kPlayer);
  EXPECT_EQ(ets.get_Entity_Type(), kPlayer);
  EXPECT_EQ(ets.activated(), true);

  ets.Accept(kRechargeStation);
  EXPECT_EQ(ets.get_Entity_Type(), kRechargeStation);
  EXPECT_EQ(ets.activated(), true);

  ets.Accept(kHomeBase);
  EXPECT_EQ(ets.get_Entity_Type(), kHomeBase);
  EXPECT_EQ(ets.activated(), true);
}

TEST(Entity_Type_Sensor, Reset) {
  EntityTypeSensor ets;

  ets.activated(true);
  ets.set_detect_range(200.0);
  ets.Accept(kRobot);

  EXPECT_EQ(ets.activated(), true);
  EXPECT_EQ(ets.get_detect_range(), 200.0);
  EXPECT_EQ(ets.get_Entity_Type(), kRobot);

  ets.Reset();
  EXPECT_EQ(ets.activated(), false);
  EXPECT_EQ(ets.get_detect_range(), 50.0);
  EXPECT_EQ(ets.get_Entity_Type(), NULL);

}

/*******************************************************************************
 * Entity Type Sensor Tests
 ******************************************************************************/
 /*******************************************************************************
  * Proximity Sensor Tests
  ******************************************************************************/

TEST(Proximity_Sensor, Constructor) {
  ProximitySensor PS;

  bool val = std::is_base_of<csci3081::Sensor, csci3081::ProximitySensor>::value;
  EXPECT_TRUE(val);

  // EXPECT_STREQ(PS.get_name(), "Proximity sensor.");
  EXPECT_EQ(PS.activated(),false);
  // EXPECT_EQ(PS.field_of_view(), 100.0);
  EXPECT_EQ(PS.get_detect_range(), 200.0);
  EXPECT_EQ(PS.get_range_left(), 0);
  EXPECT_EQ(PS.get_range_right(), 0);

}
// Proximity Sensor Constructor test.

TEST(Proximity_Sensor, setterandgetter) {
  ProximitySensor pt;

  pt.activated(true);
  // pt.field_of_view(100.0);
  pt.set_detect_range(200.0);
  pt.set_range(10.0,20.0);

  EXPECT_EQ(pt.get_range_right(), 10.0);
  EXPECT_EQ(pt.get_range_left(), 20.0);
  EXPECT_EQ(pt.get_detect_range(), 200.0);
  EXPECT_EQ(pt.activated(), true);
  // EXPECT_EQ(pt.field_of_view(), 100.0);
}
// Proximity Sensor getter and setter's test.

TEST(Proximity_Sensor, Reset){
  ProximitySensor pt;

  pt.activated(true);;
  // pt.field_of_view(150.0);
  pt.set_detect_range(150.0);
  pt.set_range(50, 50);

  EXPECT_EQ(pt.get_range_right(), 50.0);
  EXPECT_EQ(pt.get_range_left(), 50.0);
  EXPECT_EQ(pt.get_detect_range(), 150.0);
  EXPECT_EQ(pt.activated(), true);
  // EXPECT_EQ(pt.field_of_view(), 150.0);

  pt.Reset();

  EXPECT_EQ(pt.get_range_right(), 0.0);
  EXPECT_EQ(pt.get_range_left(), 0.0);
  EXPECT_EQ(pt.get_detect_range(), 200.0);
  EXPECT_EQ(pt.activated(), false);
  // EXPECT_EQ(pt.field_of_view(), 100.0);
}
// Proximity Sensor Reset() function test.

// TEST(Proximity_Sensor, foundObjects){
//   ProximitySensor pt;
//   EventProximity e;
//
//   EXPECT_EQ(pt.activated(), false);
//
//   e.distance(30.0)
//   pt.found_obj(&e);
//
//   EXPECT_EQ(pt.activated(), true);
// }
// Proximity Sensor found_obj() function test.

// TEST(Proximity_Sensor, distanceClculate){
//   ProximitySensor pt;
//
//   double distance = pt.distance_cal(Position(100.0, 200.0), Position(100.0, 150.0));
//
//   EXPECT_EQ(distance, 50.0);
// }

/*******************************************************************************
 * Proximity Sensor Tests
 ******************************************************************************/

NAMESPACE_END(csci3081);

#endif  // STUDENT_UNIT_TESTS
