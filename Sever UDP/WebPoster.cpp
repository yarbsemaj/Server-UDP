#include "WebPoster.h"
#include <curl/curl.h>
#include <iostream>
#include <string>
#include <sstream>
#include <array>
#include <chrono>
#include <thread>
#include <Windows.h>

#pragma comment(lib, "dll-debug-x86/libcurl_debug.lib")

using namespace std;

void WebPoster::start(std::vector<Aircraft>& aircrafts)
{
	using namespace chrono_literals;
	while (1) {
		//update the iterate over all aircraft
		for (int y = 0; y < aircrafts.size(); y++) {
			this_thread::sleep_for(0.5s);
			Aircraft newestAircraft = Aircraft();
			newestAircraft = aircrafts[y];

			CURL *curl;
			CURLcode res;

			/* In windows, this will init the winsock stuff */
			curl_global_init(CURL_GLOBAL_ALL);

			/* get a curl handle */
			curl = curl_easy_init();
			if (curl) {
				/* First set the URL that is about to receive our POST. This URL can
				just as well be a https:// URL if that is what should receive the
				data. */
				curl_easy_setopt(curl, CURLOPT_URL, "http://flighttracker.yarbsemaj.com/api/send.php");
				/* Now specify the POST data */
				std::ostringstream oss;
				oss << "reg=" << newestAircraft.registration << "&presure=" << newestAircraft.presure.getValue() << "&long="
					<< newestAircraft.longitude.getValue() << "&lat=" << newestAircraft.latitude.getValue()
					<< "&speed=" << newestAircraft.speed.getValue() << "&altitude=" << newestAircraft.altitude.getValue();
				std::string var = oss.str();

				//set some more options
				curl_easy_setopt(curl, CURLOPT_POST, 1);
				curl_easy_setopt(curl, CURLOPT_POSTFIELDS, var.c_str());

				/* Perform the request, res will get the return code */
				res = curl_easy_perform(curl);
				/* Check for errors */
				if (res != CURLE_OK)
					fprintf(stderr, "curl_easy_perform() failed: %s\n",
						curl_easy_strerror(res));

				/*cleanup */
				curl_easy_cleanup(curl);
			}
			curl_global_cleanup();
		}
	}
}

WebPoster::WebPoster()
{
}


WebPoster::~WebPoster()
{
}
