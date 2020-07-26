Action()
{
	lr_start_transaction("02_ChoiceTicketWithoutReservation");

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
			
			
			web_reg_find("Text/IC=A Session ID has been created",
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
		
	
		lr_start_transaction("Click_SignUp");
	
			web_add_auto_header("Sec-Fetch-Dest", 
				"frame");
		
			web_revert_auto_header("Sec-Fetch-User");
		
			web_revert_auto_header("Upgrade-Insecure-Requests");
		
			web_add_auto_header("Sec-Fetch-Site", 
				"same-origin");
			
			web_reg_find("Text/IC=User Information",
		LAST);
				
			web_url("sign up now", 
				"URL=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
				"TargetFrame=body", 
				"Resource=0", 
				"RecContentType=text/html", 
				"Referer=http://localhost:1080/WebTours/home.html", 
				"Snapshot=t2.inf", 
				"Mode=HTML", 
				LAST);
	
		lr_end_transaction("Click_SignUp",LR_AUTO);
		
		
		lr_think_time(5);
		
	
		lr_start_transaction("CreateNewProfile");
	
			web_add_header("Origin", 
				"http://localhost:1080");
		
			web_add_auto_header("Sec-Fetch-User", 
				"?1");
		
			web_add_auto_header("Upgrade-Insecure-Requests", 
				"1");
		
			
		
			web_submit_data("login.pl", 
				"Action=http://localhost:1080/cgi-bin/login.pl", 
				"Method=POST", 
				"TargetFrame=info", 
				"RecContentType=text/html", 
				"Referer=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
				"Snapshot=t3.inf", 
				"Mode=HTML", 
				ITEMDATA, 
				"Name=username", "Value=harry", ENDITEM, 
				"Name=password", "Value=0987", ENDITEM, 
				"Name=passwordConfirm", "Value=0987", ENDITEM, 
				"Name=firstName", "Value=Harry", ENDITEM, 
				"Name=lastName", "Value=Pens", ENDITEM, 
				"Name=address1", "Value=Band", ENDITEM, 
				"Name=address2", "Value=New York", ENDITEM, 
				"Name=register.x", "Value=58", ENDITEM, 
				"Name=register.y", "Value=5", ENDITEM, 
				LAST);
	
		lr_end_transaction("CreateNewProfile",LR_AUTO);
		
		
		lr_think_time(5);	
		
	
		lr_start_transaction("next_page");
	
			web_revert_auto_header("Sec-Fetch-User");
		
			web_revert_auto_header("Upgrade-Insecure-Requests");
			
			
			web_reg_find("Text/IC= User has returned to the home page",
		LAST);
				
			web_url("button_next.gif", 
				"URL=http://localhost:1080/cgi-bin/welcome.pl?page=menus", 
				"TargetFrame=body", 
				"Resource=0", 
				"RecContentType=text/html", 
				"Referer=http://localhost:1080/cgi-bin/login.pl", 
				"Snapshot=t4.inf", 
				"Mode=HTML", 
				LAST);
	
		lr_end_transaction("next_page",LR_AUTO);
		
		
		lr_think_time(5);
		
	
		lr_start_transaction("Click_Flights");
	
			web_add_auto_header("Sec-Fetch-User", 
				"?1");
		
			web_add_auto_header("Upgrade-Insecure-Requests", 
				"1");		
		
			web_url("Search Flights Button", 
				"URL=http://localhost:1080/cgi-bin/welcome.pl?page=search", 
				"TargetFrame=body", 
				"Resource=0", 
				"RecContentType=text/html", 
				"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
				"Snapshot=t5.inf", 
				"Mode=HTML", 
				LAST);
	
		lr_end_transaction("Click_Flights",LR_AUTO);
		
		
		lr_think_time(5);
		
	
		lr_start_transaction("Insert_FlightInfo");
	
			web_add_header("Origin", 
				"http://localhost:1080");
							
			web_submit_data("reservations.pl", 
				"Action=http://localhost:1080/cgi-bin/reservations.pl", 
				"Method=POST", 
				"TargetFrame=", 
				"RecContentType=text/html", 
				"Referer=http://localhost:1080/cgi-bin/reservations.pl?page=welcome", 
				"Snapshot=t6.inf", 
				"Mode=HTML", 
				ITEMDATA, 
				"Name=advanceDiscount", "Value=0", ENDITEM, 
				"Name=depart", "Value=Los Angeles", ENDITEM, 
				"Name=departDate", "Value=07/26/2020", ENDITEM, 
				"Name=arrive", "Value=Paris", ENDITEM, 
				"Name=returnDate", "Value=07/29/2020", ENDITEM, 
				"Name=numPassengers", "Value=1", ENDITEM, 
				"Name=seatPref", "Value=Window", ENDITEM, 
				"Name=seatType", "Value=First", ENDITEM, 
				"Name=findFlights.x", "Value=39", ENDITEM, 
				"Name=findFlights.y", "Value=8", ENDITEM, 
				"Name=.cgifields", "Value=roundtrip", ENDITEM, 
				"Name=.cgifields", "Value=seatType", ENDITEM, 
				"Name=.cgifields", "Value=seatPref", ENDITEM, 
				LAST);
	
		lr_end_transaction("Insert_FlightInfo",LR_AUTO);
		
				lr_think_time(53);
		
			lr_start_transaction("ChooseFlight");
	
		web_submit_data("reservations.pl_2", 
			"Action=http://localhost:1080/cgi-bin/reservations.pl", 
			"Method=POST", 
			"TargetFrame=", 
			"RecContentType=text/html", 
			"Referer=http://localhost:1080/cgi-bin/reservations.pl", 
			"Snapshot=t5.inf", 
			"Mode=HTML", 
			ITEMDATA, 
			"Name=outboundFlight", "Value=343;673;07/26/2020", ENDITEM, 
			"Name=numPassengers", "Value=1", ENDITEM, 
			"Name=advanceDiscount", "Value=0", ENDITEM, 
			"Name=seatType", "Value=First", ENDITEM, 
			"Name=seatPref", "Value=Window", ENDITEM, 
			"Name=reserveFlights.x", "Value=45", ENDITEM, 
			"Name=reserveFlights.y", "Value=8", ENDITEM, 
			LAST);
	
		lr_end_transaction("ChooseFlight",LR_AUTO);
	
	lr_end_transaction("02_ChoiceTicketWithoutReservation", LR_AUTO);


	return 0;
}