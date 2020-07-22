Action()
{
	lr_start_transaction("Покупка билета");
	
	
	lr_start_transaction("Главная страница");

	lr_end_transaction("Главная страница", LR_AUTO);
	

	lr_start_transaction("Логин");
	
		lr_start_transaction("GetLoginMode");
		
			lr_start_transaction("LoginBySMS");

			lr_end_transaction("LoginBySMS", LR_AUTO);
		
		lr_end_transaction("GetLoginMode", LR_AUTO);
	
	
		lr_start_transaction("AuthorizationType");
		
		lr_end_transaction("AuthorizationType", LR_AUTO);
		
		lr_start_transaction("SuccessLogin");
		
		lr_end_transaction("SuccessLogin", LR_AUTO);

	lr_end_transaction("Логин", LR_AUTO);

	lr_start_transaction("Оформление билета");

	lr_end_transaction("Оформление билета", LR_AUTO);
	

	lr_start_transaction("Логаут");

	lr_end_transaction("Логаут", LR_AUTO);

	

	lr_end_transaction("Покупка билета", LR_AUTO);

	
	return 0;
}
