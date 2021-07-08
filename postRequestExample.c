#include <curl/curl.h>
#include <unistd.h>
#include "post_request.h"


int main()
{
  CURL *curl;

  curl = curl_easy_init();
  if(curl) {
    post_body body;
    initializePostBody(&body, 1);
    
    setBodyMeasurementValue(&body, TEMPERATURE, 25.3);
    /*setBodyDeviceIdValue(&body, 2);
    setBodyRequest(&body);*/
    
    printf("%s\n", body.temperatureString);
    printf("%s\n", body.deviceIdString);
    printf("%s\n", body.request);
    
    
    setBodyRequest(&body);
    printf("%s\n", body.request);

    curl_easy_setopt(curl, CURLOPT_URL, "https://rtrk-iot-praksa.herokuapp.com/api/data");
    curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)strlen(body.request));
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.request);
    
    struct curl_slist *hs=NULL;
    hs = curl_slist_append(hs, "Content-Type: application/json");
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, hs);
    
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeFunc);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &body);
    
    int counter = 1;
    
    do{
      printf("Caught response in struct START\n");
      printf("%s\n", body.response);
      printf("Caught response in struct END\n");
      
      if(counter%5 == 0)
      {
	setBodyMeasurementValues(&body, 10.5, 20.5, 30.5, 40.6, 60.1, 70.2, 80.3, 90.8, 100.1, 110.42);
      }
      else
      {
	setBodyMeasurementValue(&body, counter%11 , 15.3 + counter);
      }
      
      setBodyRequest(&body);
      
      curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)strlen(body.request));
      curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.request);
      
      
      curl_easy_perform(curl);
      
      printf("============ REQUEST ===============\n");
      printf("%s\n", body.request);
      printf("============ REQUEST END ===============\n");
      
      printf("============ RESPONSE ===============\n");
      printf("%s\n", body.response);
      printf("============ RESPONSE END ===============\n");
      sleep(3);
    }while(counter++<100);
    
    

    free_body(&body);
    curl_easy_cleanup(curl);
  }
  return 0;
}

