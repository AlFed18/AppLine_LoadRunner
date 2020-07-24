Action()
{
	lr_start_transaction("02_ViewingOfTheService");
	
		
		lr_start_transaction("open_site");
	
		web_set_sockets_option("SSL_VERSION", "2&3");
	
		web_add_auto_header("Sec-Fetch-Site", 
			"none");
	
		web_add_auto_header("Sec-Fetch-Dest", 
			"document");
	
		web_add_auto_header("Sec-Fetch-Mode", 
			"navigate");
	
		web_add_auto_header("Sec-Fetch-User", 
			"?1");
	
		web_add_auto_header("Upgrade-Insecure-Requests", 
			"1");
		
//		web_reg_save_param_ex(
//		"ParamName=userSession",
//		"LB=name=\*userSession\" value=\"",
//		"RB=/">",
//		"Ordinal=1",
//		SEARCH_FILTERS,
//		LAST);

	
		web_url("WebTours", 
			"URL=http://localhost:1080/WebTours/", 
			"TargetFrame=", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=", 
			"Snapshot=t1.inf", 
			"Mode=HTML", 
			LAST);
		
		lr_end_transaction("open_site", LR_AUTO);
		
		//LOGIN
	
		lr_start_transaction("Login");
	
		web_revert_auto_header("Sec-Fetch-User");
	
		web_add_auto_header("Sec-Fetch-Dest", 
			"frame");
	
		web_revert_auto_header("Upgrade-Insecure-Requests");
	
		web_add_header("Origin", 
			"http://localhost:1080");
	
		web_add_auto_header("Sec-Fetch-Site", 
			"same-origin");
	
		lr_think_time(20);
	
		web_submit_data("login.pl", 
			"Action=http://localhost:1080/cgi-bin/login.pl", 
			"Method=POST", 
			"TargetFrame=body", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home", 
			"Snapshot=t2.inf", 
			"Mode=HTML", 
			ITEMDATA, 
			"Name=userSession", "Value=129208.391332523zztzVfzpzcQVzzzHDQiHzpQDQHHf", ENDITEM, 
			"Name=username", "Value={login}", ENDITEM, 
			"Name=password", "Value={password}", ENDITEM, 
			"Name=login.x", "Value=48", ENDITEM, 
			"Name=login.y", "Value=5", ENDITEM, 
			"Name=JSFormSubmit", "Value=off", ENDITEM, 
			LAST);
	
		lr_end_transaction("Login",LR_AUTO);
		
		//FLIGHTS
	
		lr_start_transaction("ClickFlights");
	
		web_add_auto_header("Sec-Fetch-User", 
			"?1");
	
		web_add_auto_header("Upgrade-Insecure-Requests", 
			"1");
	
		lr_think_time(25);
	
		web_url("Search Flights Button", 
			"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
			"TargetFrame=body", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
			"Snapshot=t3.inf", 
			"Mode=HTML", 
			LAST);
	
		lr_end_transaction("ClickFlights",LR_AUTO);
	
		lr_start_transaction("WatchFindFlight");
	
		web_add_auto_header("Origin", 
			"http://localhost:1080");
	
		lr_think_time(64);
	
		web_submit_data("reservations.pl", 
			"Action=http://localhost:1080/cgi-bin/reservations.pl", 
			"Method=POST", 
			"TargetFrame=", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
			"Snapshot=t4.inf", 
			"Mode=HTML", 
			ITEMDATA, 
			"Name=advanceDiscount", "Value=0", ENDITEM, 
			"Name=depart", "Value=Denver", ENDITEM, 
			"Name=departDate", "Value=07/19/2020", ENDITEM, 
			"Name=arrive", "Value=Denver", ENDITEM, 
			"Name=returnDate", "Value=07/20/2020", ENDITEM, 
			"Name=numPassengers", "Value=1", ENDITEM, 
			"Name=seatPref", "Value=None", ENDITEM, 
			"Name=seatType", "Value=Coach", ENDITEM, 
			"Name=findFlights.x", "Value=43", ENDITEM, 
			"Name=findFlights.y", "Value=8", ENDITEM, 
			"Name=.cgifields", "Value=roundtrip", ENDITEM, 
			"Name=.cgifields", "Value=seatType", ENDITEM, 
			"Name=.cgifields", "Value=seatPref", ENDITEM, 
			LAST);
	
		lr_end_transaction("WatchFindFlight",LR_AUTO);
	
		lr_think_time(105);
	
		lr_start_transaction("WatchChoiceFlight");
	
		web_submit_data("reservations.pl_2", 
			"Action=http://localhost:1080/cgi-bin/reservations.pl", 
			"Method=POST", 
			"TargetFrame=", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
			"Snapshot=t5.inf", 
			"Mode=HTML", 
			ITEMDATA, 
			"Name=outboundFlight", "Value=003;0;07/19/2020", ENDITEM, 
			"Name=numPassengers", "Value=1", ENDITEM, 
			"Name=advanceDiscount", "Value=0", ENDITEM, 
			"Name=seatType", "Value=Coach", ENDITEM, 
			"Name=seatPref", "Value=None", ENDITEM, 
			"Name=reserveFlights.x", "Value=40", ENDITEM, 
			"Name=reserveFlights.y", "Value=7", ENDITEM, 
			LAST);
	
		lr_end_transaction("WatchChoiceFlight",LR_AUTO);
	
		lr_start_transaction("WatchPaymentDetails");
	
		web_revert_auto_header("Origin");
	
		web_revert_auto_header("Sec-Fetch-User");
	
		web_revert_auto_header("Upgrade-Insecure-Requests");
	
		web_add_auto_header("Origin", 
			"http://localhost:1080");
	
		lr_think_time(49);
	
		web_submit_data("reservations.pl_3", 
			"Action=http://localhost:1080/cgi-bin/reservations.pl", 
			"Method=POST", 
			"TargetFrame=", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
			"Snapshot=t6.inf", 
			"Mode=HTML", 
			ITEMDATA, 
			"Name=firstName", "Value=Gogi", ENDITEM, 
			"Name=lastName", "Value=Mogi", ENDITEM, 
			"Name=address1", "Value=Second", ENDITEM, 
			"Name=address2", "Value=Frankfurt", ENDITEM, 
			"Name=pass1", "Value=Gogi Mogi", ENDITEM, 
			"Name=creditCard", "Value=", ENDITEM, 
			"Name=expDate", "Value=", ENDITEM, 
			"Name=oldCCOption", "Value=", ENDITEM, 
			"Name=numPassengers", "Value=1", ENDITEM, 
			"Name=seatType", "Value=Coach", ENDITEM, 
			"Name=seatPref", "Value=None", ENDITEM, 
			"Name=outboundFlight", "Value=003;0;07/19/2020", ENDITEM, 
			"Name=advanceDiscount", "Value=0", ENDITEM, 
			"Name=returnFlight", "Value=", ENDITEM, 
			"Name=JSFormSubmit", "Value=off", ENDITEM, 
			"Name=buyFlights.x", "Value=44", ENDITEM, 
			"Name=buyFlights.y", "Value=8", ENDITEM, 
			"Name=.cgifields", "Value=saveCC", ENDITEM, 
			LAST);
	
		lr_end_transaction("WatchPaymentDetails",LR_AUTO);
	
	
		lr_start_transaction("click_itinerary");
	
		web_revert_auto_header("Origin");
	
		web_revert_auto_header("Sec-Fetch-User");
	
		web_revert_auto_header("Upgrade-Insecure-Requests");
	
		web_add_auto_header("Sec-Fetch-User", 
			"?1");
	
		web_add_auto_header("Upgrade-Insecure-Requests", 
			"1");
	
		lr_think_time(55);
	
		web_url("Itinerary Button", 
			"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
			"TargetFrame=body", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
			"Snapshot=t15.inf", 
			"Mode=HTML", 
			LAST);
	
		lr_end_transaction("click_itinerary",LR_AUTO);
		
	
		lr_start_transaction("delete_flight");
	
		web_add_header("Origin", 
			"http://localhost:1080");
	
		lr_think_time(57);
	
		web_submit_data("itinerary.pl", 
			"Action=http://localhost:1080/cgi-bin/itinerary.pl", 
			"Method=POST", 
			"TargetFrame=", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
			"Snapshot=t16.inf", 
			"Mode=HTML", 
			ITEMDATA, 
			"Name=1", "Value=on", ENDITEM, 
			"Name=flightID", "Value=1-7-GM", ENDITEM, 
			"Name=flightID", "Value=0-15-GM", ENDITEM, 
			"Name=flightID", "Value=0-23-GM", ENDITEM, 
			"Name=removeFlights.x", "Value=46", ENDITEM, 
			"Name=removeFlights.y", "Value=9", ENDITEM, 
			"Name=.cgifields", "Value=1", ENDITEM, 
			"Name=.cgifields", "Value=3", ENDITEM, 
			"Name=.cgifields", "Value=2", ENDITEM, 
			LAST);
	
		lr_end_transaction("delete_flight",LR_AUTO);
		
	
		lr_start_transaction("logout");
	
		web_revert_auto_header("Sec-Fetch-User");
	
		web_add_header("Sec-Fetch-User", 
			"?1");
	
		lr_think_time(18);
	
		web_url("SignOff Button", 
			"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
			"TargetFrame=body", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
			"Snapshot=t17.inf", 
			"Mode=HTML", 
			LAST);
	
		lr_end_transaction("logout",LR_AUTO);
		
	lr_end_transaction("02_ViewingOfTheService", LR_AUTO);

	return 0;
}