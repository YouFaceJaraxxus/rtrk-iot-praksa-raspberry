#include <curl/curl.h>
#include <unistd.h>
#include "post_request.h"


int main()
{
  CURL *curl;

  curl = curl_easy_init();
  if(curl) {
    
    post_body body;
    initializePostBody(&body, 1, 1);
    
    setBodyMeasurementValue(&body, 30);
    setBodyDeviceIdValue(&body, 1);
    setBodyRequest(&body);
    
    printf("%s\n", body.measurementString);
    printf("%s\n", body.deviceIdString);
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
      curl_easy_perform(curl);

      printf("Caught response in struct START\n");
      printf("%s\n", body.response);
      printf("Caught response in struct END\n");
      
      setBodyMeasurementValue(&body, 300+counter);
      setBodyRequest(&body);
      
      curl_easy_setopt(curl, CURLOPT_POSTFIELDSIZE, (long)strlen(body.request));
      curl_easy_setopt(curl, CURLOPT_POSTFIELDS, body.request);
      
      printf("%s\n", body.measurementString);
	  printf("%s\n", body.deviceIdString);
	  printf("%s\n", body.request);
      sleep(3);
    }while(counter++<100);
    
    

    free_body(&body);
    /* always cleanup */
    curl_easy_cleanup(curl);
  }
  return 0;
}

