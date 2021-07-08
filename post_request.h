#ifndef POST_REQUEST_H
#define POST_REQUEST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>
#include <unistd.h>
#define BUFFER_SIZE 10240 //10 kB
#define VALUE_STRING_SIZE 20 //10 kB
#define DEVICE_ID_STRING_SIZE 10 //10 kB
#define TEMPERATURE 1
#define GYRO_X 2
#define GYRO_Y 3
#define GYRO_Z 4
#define ACC_X 5
#define ACC_Y 6
#define ACC_Z 7
#define MAG_X 8
#define MAG_Y 9
#define MAG_Z 10

typedef struct post_body {
  int deviceId;
  float temperatureValue;
  float gyroXValue;
  float gyroYValue;
  float gyroZValue;
  float accXValue;
  float accYValue;
  float accZValue;
  float magXValue;
  float magYValue;
  float magZValue;
  
  char *deviceIdString;
  char *temperatureString;
  char *gyroXString;
  char *gyroYString;
  char *gyroZString;
  char *accXString;
  char *accYString;
  char *accZString;
  char *magXString;
  char *magYString;
  char *magZString;
  
  char *request;
  char *response;
} post_body;


void initializePostBody(post_body *body, int deviceId);
void setBodyStrings(post_body *body);
void setBodyMeasurementValue(post_body* body, int key, float value);
void setBodyMeasurementValues(
  post_body* body, 
  float temperatureValue,
  float gyroXValue,
  float gyroYValue,
  float gyroZValue,
  float accXValue,
  float accYValue,
  float accZValue,
  float magXValue,
  float magYValue,
  float magZValue
);
void setBodyDeviceIdValue(post_body* body, int deviceId);
void setBodyRequest(post_body* body);
void free_body(post_body *body);
size_t writeFunc(void *ptr, size_t size, size_t nmemb, post_body *body);

#endif /* POST_REQUEST_H */
