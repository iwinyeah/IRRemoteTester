#include <Arduino.h>
#include <unity.h>
#include <WString.h>

// void setUp(void) {
// // set stuff up here
// }

// void tearDown(void) {
// // clean stuff up here
// }
#define LED_PIN D0

void test_LED_PIN_pin_number(void) {
    TEST_ASSERT_EQUAL(16, LED_PIN);
}

void test_led_state_high(void) {
    digitalWrite(LED_PIN, HIGH);
    TEST_ASSERT_EQUAL(HIGH, digitalRead(LED_PIN));
}

void test_led_state_low(void) {
    digitalWrite(LED_PIN, LOW);
    TEST_ASSERT_EQUAL(LOW, digitalRead(LED_PIN));
}

void setup() {
		String tStr;

    // NOTE!!! Wait for >2 secs
    // if board doesn't support software reset via Serial.DTR/RTS
    delay(2000);

    UNITY_BEGIN();    // IMPORTANT LINE!
    RUN_TEST(test_LED_PIN_pin_number);

    pinMode(LED_PIN, OUTPUT);
}

uint8_t i = 0;
uint8_t max_blinks = 5;

void loop() {
    if (i < max_blinks)
    {
        RUN_TEST(test_led_state_high);
        delay(500);
        RUN_TEST(test_led_state_low);
        delay(500);
        i++;
    }
    else if (i == max_blinks) {
      UNITY_END(); // stop unit testing
    }
}