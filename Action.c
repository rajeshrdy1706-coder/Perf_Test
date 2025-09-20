Action()
{

	lr_start_transaction("Launch");

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("Accept-Language", 
		"en-US,en;q=0.5");

	web_url("petstore.octoperf.com", 
		"URL=https://petstore.octoperf.com/", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Launch",LR_AUTO);

	lr_start_transaction("Enter the Store");

	web_url("Enter the Store", 
		"URL=https://petstore.octoperf.com/actions/Catalog.action", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Enter the Store",LR_AUTO);

	lr_think_time(6);

	lr_start_transaction("Login");

	web_url("Sign In", 
		"URL=https://petstore.octoperf.com/actions/Account.action;jsessionid=99167B314E53118C26C76A9D1EE6D473?signonForm=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		LAST);

	web_submit_data("Account.action", 
		"Action=https://petstore.octoperf.com/actions/Account.action", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Account.action;jsessionid=99167B314E53118C26C76A9D1EE6D473?signonForm=", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value=one", ENDITEM, 
		"Name=password", "Value=one", ENDITEM, 
		"Name=signon", "Value=Login", ENDITEM, 
		"Name=_sourcePage", "Value=Ob1LRKltQZG5m6Nu0XB8EvrTFYkqQhInMs0lVblVjLlqDU8s4tuH5IKVNRHjlXtsGv9XK6pbI3f_qNxtDJYelwRMwzB3SZ1y-TL9EfNfKDw=", ENDITEM, 
		"Name=__fp", "Value=YgHyhQN8HVCa0KgKCjhNZG02XkE0SC8k6BBL_TLFTBhoNij21CETquA5GWE_ATtx", ENDITEM, 
		LAST);

	lr_end_transaction("Login",LR_AUTO);

	lr_think_time(14);

	lr_start_transaction("click on Pet");

	web_url("sm_fish.gif", 
		"URL=https://petstore.octoperf.com/actions/Catalog.action?viewCategory=&categoryId=FISH", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("click on Pet",LR_AUTO);

	lr_start_transaction("Logout");

	web_url("Sign Out", 
		"URL=https://petstore.octoperf.com/actions/Account.action?signoff=", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=https://petstore.octoperf.com/actions/Catalog.action?viewCategory=&categoryId=FISH", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("Logout",LR_AUTO);

	return 0;
}