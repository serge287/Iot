#include "Global.h"

#include "JsonUtils.h"

TickerScheduler ts(TEST + 1);

WiFiClient espClient;
PubSubClient client_mqtt(espClient);
StringCommand sCmd;

// Web
AsyncWebServer server(80);

#ifdef WS_enable
AsyncWebSocket ws("/ws");
#endif

AsyncEventSource events("/events");

// Global vars
boolean just_load = true;
const char *hostName = "IoT Manager";

// Json
String configSetupJson = "{}";
String configLiveJson = "{}";
String configOptionJson = "{}";

// Mqtt
String chipID = "";
String prex;
String all_widgets = "";
String scenario;
String order_loop;

// Sensors
String analog_value_names_list;
int enter_to_analog_counter;

String level_value_name;

String dhtT_value_name;
String dhtH_value_name;

String bmp280T_value_name;
String bmp280P_value_name;

String bme280T_value_name;
String bme280P_value_name;
String bme280H_value_name;
String bme280A_value_name;

int sensors_reading_map[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

// Logging
String logging_value_names_list;
int enter_to_logging_counter;

// Ntp and time
String current_time;

// Scenario
int scenario_line_status[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};

// Errors
int wifi_lost_error = 0;
int mqtt_lost_error = 0;

String last_version;

// Async actions
boolean upgrade_url = false;
boolean upgrade = false;
boolean mqtt_connection = false;
boolean udp_data_parse = false;
boolean mqtt_send_settings_to_udp = false;
boolean i2c_scanning = false;

// Servo
Servo myServo1;
Servo myServo2;

//Buttons
boolean but[NUM_BUTTONS];
Bounce *buttons = new Bounce[NUM_BUTTONS];

// Udp
boolean udp_busy = false;
unsigned int udp_port = 4210;
#ifdef ESP8266
IPAddress udp_multicastIP(255, 255, 255, 255);
#endif
#ifdef ESP32
IPAddress udp_multicastIP(239, 255, 255, 255);
AsyncUDP udp;
#endif
String received_ip;
String received_udp_line;
int udp_period;

// i2c
String i2c_list;

OneWire *oneWire;
DallasTemperature sensors;

DHTesp dht;

#ifdef level_enable
GMedian<10, int> medianFilter;
#endif

#ifdef bmp_enable
Adafruit_BMP280 bmp;
Adafruit_Sensor *bmp_temp = bmp.getTemperatureSensor();
Adafruit_Sensor *bmp_pressure = bmp.getPressureSensor();
#endif

#ifdef bme_enable
Adafruit_BME280 bme;
Adafruit_Sensor *bme_temp = bme.getTemperatureSensor();
Adafruit_Sensor *bme_pressure = bme.getPressureSensor();
Adafruit_Sensor *bme_humidity = bme.getHumiditySensor();
#endif
