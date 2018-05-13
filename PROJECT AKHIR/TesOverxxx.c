
		if(pilover == 1)
	{
		//SOMETHING
		fflush(stdin);
	}
	else if(pilover == 2)
	{
		fflush(stdin);
		return main();
	}
	else
	{
		printf("\n\aPilihan Invalid, Mohon Coba Lagi : ");
		fflush(stdin);
		goto inputover;
	}
