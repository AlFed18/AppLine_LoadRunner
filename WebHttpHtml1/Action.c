Action()
{
	lr_start_transaction("������� ������");
	
	
	lr_start_transaction("������� ��������");

	lr_end_transaction("������� ��������", LR_AUTO);
	

	lr_start_transaction("�����");
	
		lr_start_transaction("GetLoginMode");
		
			lr_start_transaction("LoginBySMS");

			lr_end_transaction("LoginBySMS", LR_AUTO);
		
		lr_end_transaction("GetLoginMode", LR_AUTO);
	
	
		lr_start_transaction("AuthorizationType");
		
		lr_end_transaction("AuthorizationType", LR_AUTO);
		
		lr_start_transaction("SuccessLogin");
		
		lr_end_transaction("SuccessLogin", LR_AUTO);

	lr_end_transaction("�����", LR_AUTO);

	lr_start_transaction("���������� ������");

	lr_end_transaction("���������� ������", LR_AUTO);
	

	lr_start_transaction("������");

	lr_end_transaction("������", LR_AUTO);

	

	lr_end_transaction("������� ������", LR_AUTO);

	
	return 0;
}
