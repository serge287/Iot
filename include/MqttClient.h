#pragma once
#include "Const.h"
#include "classes/NotAsync.h"
#include "Global.h"
#include "Utils/WiFiUtils.h"

void mqttInit();
void selectBroker();
void getMqttData();
void getMqttData2();
bool isSecondBrokerSet();
boolean mqttConnect();
void mqttReconnect();
void mqttLoop();
void mqttSubscribe();

boolean publish(const String& topic, const String& data);
boolean publishData(const String& topic, const String& data);
boolean publishChart(const String& topic, const String& data);
boolean publishControl(String id, String topic, String state);
boolean publishChart_test(const String& topic, const String& data);
boolean publishStatusMqtt(const String& topic, const String& data);
boolean publishEvent(const String& topic, const String& data);
boolean publishInfo(const String& topic, const String& data);
boolean publishAnyJsonKey(const String& topic, const String& key, const String& data);

void publishWidgets();
void publishState();

void mqttCallback(char* topic, uint8_t* payload, size_t length);
const String getStateStr();
