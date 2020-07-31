Action()
{
	lr_start_transaction("01_UserRegistration");
		
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
				"Snapshot=t9.inf", 
				"Mode=HTML", 
				LAST);
	
		lr_end_transaction("OpenSite", LR_AUTO);		
		
		lr_think_time(5);
		
		/* Registration */
	
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
				"Snapshot=t10.inf", 
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
			
			
//			web_reg_find("Text/IC=Welcome to Web Tours",
//		LAST);
		
			web_submit_data("login.pl", 
				"Action=http://localhost:1080/cgi-bin/login.pl", 
				"Method=POST", 
				"TargetFrame=info", 
				"RecContentType=text/html", 
				"Referer=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
				"Snapshot=t11.inf", 
				"Mode=HTML", 
				ITEMDATA, 
				"Name=username", "Value={login}", ENDITEM, 
				"Name=password", "Value={password}", ENDITEM, 
				"Name=passwordConfirm", "Value={passConfirm}", ENDITEM, 
				"Name=firstName", "Value={firstName}", ENDITEM, 
				"Name=lastName", "Value={lastName}", ENDITEM, 
				"Name=address1", "Value={street}", ENDITEM, 
				"Name=address2", "Value={city}", ENDITEM, 
				"Name=register.x", "Value=49", ENDITEM, 
				"Name=register.y", "Value=8", ENDITEM, 
				LAST);
		
		lr_end_transaction("CreateNewProfile",LR_AUTO);
				
		lr_think_time(5);		
	
		lr_start_transaction("nextPage");
	
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
				"Snapshot=t12.inf", 
				"Mode=HTML", 
				LAST);
		
		lr_end_transaction("nextPage",LR_AUTO);
				
		lr_think_time(5);		
	
		lr_start_transaction("Logout");
	
			web_add_header("Sec-Fetch-User", 
				"?1");
		
			web_add_header("Upgrade-Insecure-Requests", 
				"1");
							
			web_reg_find("Text/IC=A Session ID has been created",
		LAST);
		
			web_url("SignOff Button", 
				"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
				"TargetFrame=body", 
				"Resource=0", 
				"RecContentType=text/html", 
				"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
				"Snapshot=t13.inf", 
				"Mode=HTML", 
				LAST);
	
		lr_end_transaction("Logout",LR_AUTO);
	
	lr_end_transaction("01_UserRegistration", LR_AUTO);

	return 0;
}