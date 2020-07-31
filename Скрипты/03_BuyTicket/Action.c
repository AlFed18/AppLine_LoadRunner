Action()
{
	lr_start_transaction("03_BuyTicket");
	
		lr_start_transaction("OpenSite");
	
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
						
			web_reg_find("Text/IC= A Session ID has been created ",
		LAST);
		
		/*Correlation comment - Do not change!  Original value='129214.170676387zztztfDpQAtVzzzHDQiHipHcDtcf' Name ='userSession' Type ='ResponseBased'*/
//	web_reg_save_param_attrib(
//		"ParamName=userSession",
//		"TagName=input",
//		"Extract=value",
//		"Name=userSession",
//		"Type=hidden",
//		SEARCH_FILTERS,
//		"IgnoreRedirections=No",
//		"RequestUrl=*/nav.pl*",
//		LAST);
//				
			web_reg_save_param_ex(
			"ParamName=userSession",
			"LB=name=\"userSession\" value=\"",
			"RB=\"/>",
			"Ordinal=1",
			SEARCH_FILTERS,
			LAST);
	
			web_url("WebTours", 
						"URL=http://localhost:1080/WebTours/", 
						"TargetFrame=", 
						"Resource=0", 
						"RecContentType=text/html", 
						"Referer=", 
						"Snapshot=t1.inf", 
						"Mode=HTML", 
						LAST);
			
		lr_end_transaction("OpenSite", LR_AUTO);
				
		lr_think_time(5);		
	
		lr_start_transaction("Login");
	
			web_revert_auto_header("Sec-Fetch-User");
		
			web_add_auto_header("Sec-Fetch-Dest", 
				"frame");
		
			web_revert_auto_header("Upgrade-Insecure-Requests");
		
			web_add_header("Origin", 
				"http://localhost:1080");
		
			web_add_auto_header("Sec-Fetch-Site", 
				"same-origin");
						
			web_reg_find("Text/IC=User password was correct",
		LAST);	

			
		
			web_submit_data("login.pl",
		"Action=http://localhost:1080/cgi-bin/login.pl",
		"Method=POST",
		"TargetFrame=body",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home",
		"Snapshot=t2.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=userSession", "Value={userSession}", ENDITEM,
		"Name=username", "Value={login}", ENDITEM,
		"Name=password", "Value={password}", ENDITEM,
		"Name=login.x", "Value=55", ENDITEM,
		"Name=login.y", "Value=8", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		LAST);
	
		lr_end_transaction("Login",LR_AUTO);
				
		lr_think_time(5);
			
		lr_start_transaction("Click_Flights");
	
			web_add_auto_header("Sec-Fetch-User", 
				"?1");
		
			web_add_auto_header("Upgrade-Insecure-Requests", 
				"1");
				
			web_reg_find("Text/IC=Flight Selections",
		LAST);
		
			web_url("Search Flights Button", 
				"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
				"TargetFrame=body", 
				"Resource=0", 
				"RecContentType=text/html", 
				"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
				"Snapshot=t3.inf", 
				"Mode=HTML", 
				LAST);
		
			lr_end_transaction("Click_Flights",LR_AUTO);
							
			lr_think_time(5);						
		
			lr_start_transaction("Insert_FlightInfo");
		
				web_add_auto_header("Origin", 
					"http://localhost:1080");
							
				web_reg_find("Text/IC=Flight Selections",
			LAST);
				
			/*Correlation comment - Do not change!  Original value='142;176;07/20/2020' Name ='outboundFlight' Type ='ResponseBased'*/
		web_reg_save_param_attrib(
			"ParamName=outboundFlight",
			"TagName=input",
			"Extract=value",
			"Name=outboundFlight",
			"Type=radio",
			SEARCH_FILTERS,
			"IgnoreRedirections=No",
			LAST);
	
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
						"Name=depart", "Value={departCity}", ENDITEM, 
						"Name=departDate", "Value={departDate}", ENDITEM, 
						"Name=arrive", "Value={arriveCity}", ENDITEM, 
						"Name=returnDate", "Value={returnDate}", ENDITEM, 
						"Name=numPassengers", "Value={numPassengers}", ENDITEM, 
						"Name=seatPref", "Value={seatPref}", ENDITEM, 
						"Name=seatType", "Value={seatType}", ENDITEM, 
						"Name=findFlights.x", "Value=69", ENDITEM, 
						"Name=findFlights.y", "Value=9", ENDITEM, 
						"Name=.cgifields", "Value=roundtrip", ENDITEM, 
						"Name=.cgifields", "Value=seatType", ENDITEM, 
						"Name=.cgifields", "Value=seatPref", ENDITEM, 
						LAST);
	
		lr_end_transaction("Insert_FlightInfo",LR_AUTO);
		
		lr_think_time(5);
	
		lr_start_transaction("Choose_Flight");		
		
			web_reg_find("Text/IC=Flight Reservation",
		LAST);
	
			web_submit_data("reservations.pl_2",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl",
		"Snapshot=t5.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM,
		"Name=numPassengers", "Value={numPassengers}", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=seatType", "Value={seatType}", ENDITEM,
		"Name=seatPref", "Value={seatPref}", ENDITEM,
		"Name=reserveFlights.x", "Value=45", ENDITEM,
		"Name=reserveFlights.y", "Value=6", ENDITEM,
		LAST);
	
		lr_end_transaction("Choose_Flight",LR_AUTO);		
		
		lr_think_time(5);		
	
		lr_start_transaction("Insert_PaymentDetails");
	
			web_revert_auto_header("Origin");
		
			web_revert_auto_header("Sec-Fetch-User");
		
			web_revert_auto_header("Upgrade-Insecure-Requests");
		
			web_add_header("Origin", 
				"http://localhost:1080");
		
			
			web_reg_find("Text/IC=Reservation Made!",
		LAST);
			
//			web_reg_find("Text/IC={departCity}  for {arriveCity}",
//		LAST);

	web_reg_find("Fail=NotFound",
		"Text/IC={departCity}  for {arriveCity}",
		LAST);

		
			web_submit_data("reservations.pl_3",
		"Action=http://localhost:1080/cgi-bin/reservations.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/reservations.pl",
		"Snapshot=t6.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=firstName", "Value={firstName}", ENDITEM,
		"Name=lastName", "Value={lastName}", ENDITEM,
		"Name=address1", "Value={street}", ENDITEM,
		"Name=address2", "Value={city}", ENDITEM,
		"Name=pass1", "Value={firstName} {lastName}", ENDITEM,
		"Name=creditCard", "Value={creditCard}", ENDITEM,
		"Name=expDate", "Value={expDate}", ENDITEM,
		"Name=saveCC", "Value=on", ENDITEM,
		"Name=oldCCOption", "Value=", ENDITEM,
		"Name=numPassengers", "Value={numPassengers}", ENDITEM,
		"Name=seatType", "Value={seatType}", ENDITEM,
		"Name=seatPref", "Value={seatPref}", ENDITEM,
		"Name=outboundFlight", "Value={outboundFlight}", ENDITEM,
		"Name=advanceDiscount", "Value=0", ENDITEM,
		"Name=returnFlight", "Value=", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		"Name=buyFlights.x", "Value=54", ENDITEM,
		"Name=buyFlights.y", "Value=11", ENDITEM,
		"Name=.cgifields", "Value=saveCC", ENDITEM,
		LAST);
	
		lr_end_transaction("Insert_PaymentDetails",LR_AUTO);	
		
		lr_think_time(5);		
	
		lr_start_transaction("Click_Itinerary");
	
		web_add_auto_header("Sec-Fetch-User", 
			"?1");
	
		web_add_auto_header("Upgrade-Insecure-Requests", 
			"1");
			
		web_reg_find("Text/IC= User wants the intineraries",
		LAST);

		web_reg_save_param_ex(
		"ParamName=FlightsId",
		"LB=name=\"flightID\" value=\"",
		"RB=\"  />",
		"Ordinal=ALL",
		SEARCH_FILTERS,
		LAST);

		
	
		web_url("Itinerary Button", 
			"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
			"TargetFrame=body", 
			"Resource=0", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=flights", 
			"Snapshot=t7.inf", 
			"Mode=HTML", 
			LAST);
		
		lr_output_message(lr_eval_string("{FlightsId}_count"));

		lr_end_transaction("Click_Itinerary",LR_AUTO);		
		
		lr_think_time(5);		
	
		lr_start_transaction("Logout");
	
			web_revert_auto_header("Sec-Fetch-User");			
		
			web_reg_find("Text/IC=Web Tours Navigation Bar",
		LAST);
		
			web_url("SignOff Button", 
				"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
				"TargetFrame=body", 
				"Resource=0", 
				"RecContentType=text/html", 
				"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
				"Snapshot=t8.inf", 
				"Mode=HTML", 
				LAST);
	
		lr_end_transaction("Logout",LR_AUTO);
		
	lr_end_transaction("03_BuyTicket", LR_AUTO);

	return 0;
}