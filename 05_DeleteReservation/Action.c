Action()
{
	lr_start_transaction("05_DeleteReservation");

	
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
			
			web_reg_find("Text/IC=Web Tours Navigation Bar",
		LAST);

		web_reg_find("Text/IC=A Session ID has been created",
		LAST);

		
		/*Correlation comment - Do not change!  Original value='129257.91381126zztiHADpQtVzzzzHDQiQcpccDzf' Name ='userSession' Type ='ResponseBased'*/
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
		
		
		
	
		lr_start_transaction("Login");
	
			web_revert_auto_header("Sec-Fetch-User");
		
			web_add_auto_header("Sec-Fetch-Dest", 
				"frame");
		
			web_revert_auto_header("Upgrade-Insecure-Requests");
		
			web_add_header("Origin", 
				"http://localhost:1080");
		
			web_add_auto_header("Sec-Fetch-Site", 
				"same-origin");
		
			lr_think_time(17);
		
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
		"Name=username", "Value=gogi", ENDITEM,
		"Name=password", "Value=qwerty", ENDITEM,
		"Name=login.x", "Value=53", ENDITEM,
		"Name=login.y", "Value=4", ENDITEM,
		"Name=JSFormSubmit", "Value=off", ENDITEM,
		LAST);
	
		lr_end_transaction("Login",LR_AUTO);
		
		
		
		
	
		lr_start_transaction("Click_Itinerary");
	
			web_add_auto_header("Sec-Fetch-User", 
				"?1");
		
			web_add_auto_header("Upgrade-Insecure-Requests", 
				"1");
		
			lr_think_time(18);
			
			web_reg_find("Text/IC=User wants the intineraries",
		LAST);

		
		/*Correlation comment - Do not change!  Original value='42687-1163251-GM' Name ='flightID' Type ='ResponseBased'*/
//		web_reg_save_param_attrib(
//			"ParamName=flightID",
//			"TagName=input",
//			"Extract=value",
//			"Name=flightID",
//			"Type=hidden",
//			SEARCH_FILTERS,
//			"IgnoreRedirections=No",
//			"RequestUrl=*/itinerary.pl*",
//			LAST);
		
		web_reg_save_param_ex(
		"ParamName=flightId",
		"LB=name=\"flightID\" value=\"",
		"RB=\"/>",
		"Ordinal=1",
		SEARCH_FILTERS,
		LAST);

		

	web_url("Itinerary Button", 
				"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
				"TargetFrame=body", 
				"Resource=0", 
				"RecContentType=text/html", 
				"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
				"Snapshot=t3.inf", 
				"Mode=HTML", 
				LAST);
	
		lr_end_transaction("Click_Itinerary",LR_AUTO);
		
		
		
		
		
	
		lr_start_transaction("DeleteReservation");
	
			web_add_header("Origin", 
				"http://localhost:1080");
		
			lr_think_time(24);
		
			web_submit_data("itinerary.pl",
		"Action=http://localhost:1080/cgi-bin/itinerary.pl",
		"Method=POST",
		"TargetFrame=",
		"RecContentType=text/html",
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl",
		"Snapshot=t4.inf",
		"Mode=HTML",
		ITEMDATA,
		"Name=1", "Value=on", ENDITEM,
		"Name=flightID", "Value={flightID}", ENDITEM,
		"Name=removeFlights.x", "Value=61", ENDITEM,
		"Name=removeFlights.y", "Value=8", ENDITEM,
		"Name=.cgifields", "Value=1", ENDITEM,
		LAST);
	
		lr_end_transaction("DeleteReservation",LR_AUTO);
		
		
		lr_think_time(5);
		
	
		lr_start_transaction("Logout");
	
			web_revert_auto_header("Sec-Fetch-User");
		
			web_add_header("Sec-Fetch-User", 
				"?1");
		
			
			web_reg_find("Text/IC=Web Tours Navigation Ba",
		LAST);

		
			web_url("SignOff Button", 
				"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
				"TargetFrame=body", 
				"Resource=0", 
				"RecContentType=text/html", 
				"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
				"Snapshot=t5.inf", 
				"Mode=HTML", 
				LAST);
	
		lr_end_transaction("Logout",LR_AUTO);
	
	lr_end_transaction("05_DeleteReservation", LR_AUTO);

	return 0;
}