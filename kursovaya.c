#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>
 //исправить внешний тейк
 //исправить указатели в удалении следущ во внешнем, сделать пустым весь список
 typedef struct vnutren{   //внутренняя структура-предложение (односвяз список слов)
	 struct vnutren* next;
	 char c[20];
}vnutren ;

typedef struct vneshni{ // список внешний для переключения между односвязными списками
	  struct vnutren *begin;
	  struct vneshni* next;
} vneshni;

int Start_p=0;
int Start_w=0;
int col=0;
int flag_print=0;
vnutren *it; //рабочий указатель в предложении
vnutren *nachalo;// указатель на начало предложения

vneshni *that; //рабочий указатель переключателя
vneshni *first;//указатель на начало внешнего списка


void start(void);
void empty(void);//
int is_empty (void);//
void begin_spis (void);//
void is_begin (void);
void next (void);
void print_next (void);
void delete_next (void);
void take_next (void);// Print_Next+Delete_Next
void change_next (void);
void add_next (void);
void print_all (void);
void end (void);   // Clear All

void menu2(void);
//void vnut_delete_next(void);
void vnut_empty(void);
int vnut_is_empty(void);
void vnut_begin_predl(void);
void vnut_is_begin(void);
void vnut_next(void);
void vnut_print_next(void);
void vnut_delete_next(void);
void vnut_take_next(void);
void vnut_change_next(void);
void vnut_add_slovo(void);
void print_one(void);
void vnut_is_end(void);// проверка на конец 

//void vnut_end(void);
void vnut_start(void);



void main (void){

int star_work=0;
printf("Enter your choice:\n 1.Start working\n 2.Make list empty\n 3.Is it empty?\n 4.Peredvinut' na nachalo spiska\n 5.Is the pointer on the begining\n 6.Peredvinut' ukaz na sled element\n 7.Print the element after the pointer\n 8.Delete the element after the pointer\n 9.Take the element and delete it\n 10.Change the elemennt after the pointer\n 11.Add the element after the pointer\n 12.Print all\n 13.End work and delete all\n");
scanf("%d", &star_work);

 switch(star_work){
	 case 1: start();
     print_all();
	 break;
	 case 2: empty();  // делает список пустым
	 print_all();
	 break;
	 case 3:   // проверяет пуст ли список предложений (нет ни одного предложения?)
			if (Start_p== 1){

			if(is_empty()==1){
						  printf("List is empty\n");
							 }
			if(is_empty()==0){
						  printf("List isn't empty\n");}
							 }
			else
						  printf("You can't work without starting working\n");

	 break;
	 case 4: begin_spis();   // передвигает рабочий указатель на начало списка
	 print_all();
	 break;
	 case 5: is_begin();   // проверяет указатель рабочий на начале или нет
	 print_all();
	 break;
	 case 6: next();  // двигаем раб. указатель на следующий элемент
	 print_all();
	 break;
	 case 7: print_next();  // печатаем предложение
	 print_all();
	 break;
	 case 8: delete_next();   // удаляет следующий после рабочего указателя элемент (т.е. предложение), и чистит все его слова
	 //print_all();
	 break;
	 case 9: take_next(); // печатаем этот элемент и удаляем его
	 print_all();
	 break;
	 case 10: change_next();// вызывает menu2();

	 //if(that->next->begin == NULL )
	  //delete_next();
	 print_all();
	 break;
	 case 11: add_next(); // вызывает menu();
	 print_all();
	 break;
	 case 12: print_all (); // печатает всё
	 print_all();
	 break;
	 case 13: end(); // удалает все
     print_all();
	 default:
	 printf("The Input is incorrect, try again\n");
		  break;

 }
 //print_all();
 printf("Press \"Any Key\" to continue\n");
	   getch();
		system("cls");

		 main();

getch();
}

void start(void){
	 if(Start_p==0){

	   Start_p=1;
	   if (Start_p==1) {
	   printf("The work can be started\n");

	   }
		}
	  else
	  {printf("You have already started work\n");
	  }

}

void empty(){

	if(Start_p==0)
	  printf("You can't work without starting working\n");

	else
	{
		 if(is_empty()== 0)
		 { vneshni *deleting;

					  while(that!=NULL)
				{
				deleting=(vneshni *)malloc(sizeof(vneshni));
						   that=first->next;
						   deleting=first->next;
							   nachalo=that->begin;
							   it=nachalo;//it=that->begin->next;
							   vnut_empty();
						   that=that->next;
						   first->next=that;
							  free(deleting);				}


			   nachalo= NULL;
			   that=NULL;
			   first=NULL;
			   it=NULL;

	  if(that == NULL && that == NULL && nachalo == NULL && it== NULL)
	  printf("Vse uspeshno ochisheno!\n");
	  }

	  else
	   printf("Your List is already empty\n");
		 }
			 }

int is_empty(){

	  if(first==NULL) //&& nachalo==NULL)
	  {
		return 1;
	  }
	  else
		{
			return 0;
		}
}

void begin_spis(){// двигвем раб указатель в главной структуре на начало к 1-ому предложению
	 if(Start_p==0 && is_empty()==1){

			if(Start_p==0)
			{
			 printf("You can't work without starting working\n");
			}
			else{
			 printf("List is empty\n");
				}
									}
	 else{
		  if(first== NULL){
		  printf("Nachalo doesn't exist!\n");

		  }
		 else{
		 that=first->next;
		 printf("Pointer on the begining\n");
		 }
		 }
				 }

void is_begin() {// проверяем раб указатель на начале списка?
				   if(Start_p==0 || is_empty()==1){

			if(Start_p==0)
			{
			 printf("You can't work without starting working\n");
			}
			else{
			 printf("List is empty\n");
				}
												}
				else{
					if(that!=first->next){
						   printf("NO!\n");
								   }
					else{
						 printf("YES!\n");
						}
					}
				}


void next()// передвигаем указатель на следующий элемент в списке
{
	//vneshni *saving_that;
	//vnutren *saving_it;

	if(Start_p==0 || is_empty()==1){

			if(Start_p==0)
			{
			 printf("You can't work without starting working\n");
			}
			else{
			 printf("List is empty\n");}
								  }

			 else {
					if(that->next!=NULL){

						that=that->next;  //двигаем рабочий указатель на следующий элемент
						  nachalo=that->begin;    // какая то проблема
							it=nachalo;        //в предложении двигаемся к первому слову (массиву)
							 printf("Pointer has been moved\n");
							 //print_one();
							 //printf("\n");
										}
					else
						printf("This element doesn't exist.Out of list\n");

				  //it=saving_it;
				  //that= saving_that;
				  }
}// нужно редактировать


void print_next()// доделать
{
			vneshni *save_that;
			vnutren *save_it;
		if(Start_p==1 && is_empty()==0)
		  {
				if(that!= NULL)
				{
				 save_that=that;
				 save_it=it;
				 that=that->next;  // перелистнули на следующий элемент переключателя
				 if(that!=NULL)
				 {nachalo=that->begin;  // присвоили поле данных переключателя(хранит начала предложений) указателю на начало предложения
				 it=nachalo;
				   print_one();
				   printf("\n");}
				 else
					printf("Can't reach element!\n");

				} // рабочий указатель передвинулся на начало уже нужного предложения, нужно его распечатать
				else
				printf("Can't reach this element\n");

			it=save_it;
			that=save_that;// вернулись обратно
			}
		 else
		 {
		   if(Start_p==0)
			printf("At first please start work\n");
		   else if(is_empty()==1)
			printf("List is empty\n");
		   }
}
void delete_next()  // исправлено
{   vneshni *save_that;
	vneshni *save_it;

	vneshni *delet;// он нужен для сохранения адресных полей и перераспределения их
	delet=( vneshni* )malloc(sizeof(vneshni));

	save_that=that;
	save_it=it;

	if(delet==NULL)
	{
		printf("Memory wasn't allocated!!!!!\n");
		exit(0);
	}


	else
	{
		if(Start_p==0 || is_empty()==1)
		{
			if(Start_p==0)
			{
			 printf("You can't work without starting working\n");
			}
			else
			{
			 printf("List is empty\n");
			 }
		}


		else
		{ //если работа начата и список не пуст
			   //	save_that=that;
			   //	save_it=it;
			   if(that->next->next == NULL)//удаление последнего элемента списка
			  {
				//save_that=that;
				//save_it=it;

				delet=that->next;
				nachalo=that->next->begin;
				vnut_empty();
				that->next=NULL;
				free(delet);

				if(vnut_is_empty()== 1)
				printf("Poslednee Pedlozhenie udaleno!!!\n");
				else
				printf("Something went wrong with deleting of the element in the end\n");

				it=save_it;
				that=save_that;
				nachalo=that->begin;
			  }

			  else if(that->next->next != NULL )//удаление в середине списка предложений
			  { //save_that=that;
				//save_it=it;

				delet=that->next;
				nachalo=that->next->begin; // начало следующего
				vnut_empty();  // очищаем предложение
				that->next=that->next->next;
				free(delet);
				//free(nachalo->next);// free(nachalo->next);
				if(vnut_is_empty()== 1)
				printf("Predlozhenie udaleno\n");
				else
				 printf("Something went wrong with deleting of the element in the middle\n");

				that=save_that;
				nachalo=that->begin;
				it=save_it;
			  }

			  else
				printf("Something went wrong with deleting!\n");
		}

	}

}
void take_next(){
	 vnutren *save_nachalo, *save_it;
	 vneshni *save_that;
	 if(Start_p==0 || is_empty()== 1){

			if(Start_p==0)
			{
			 printf("You can't work without starting working\n");
			}
			else{
			 printf("List is empty\n");}
								  }
		else
		{
		save_nachalo=nachalo;
		save_that=that;
		save_it=it;// сохранились

		if(that->next!= NULL)
		{
		//that=that->next;

		printf("The Taken Element will be deleted\n");

		that=that->next;
		nachalo=that->begin;
		it=nachalo; // перешли на следующее предложение

		print_one();
		nachalo=save_nachalo;
		that=save_that;
		it=save_it;
		printf("\n");
		//vnut_empty();
		printf("Is deleted\n");

		nachalo=save_nachalo;
		that=save_that;
        it=save_it;

		delete_next();
		printf("Uspeshno!\n");

		}
		else
		 printf("Can't take element!\n");


	   nachalo=save_nachalo;
	   that=save_that;

		   }
		}
void change_next(){
vneshni* save;
if(Start_p==0 || is_empty()== 1){

			if(Start_p==0)
			{
			 printf("You can't work without starting working\n");
			}
			else{
			 printf("List is empty\n");}
								  }
else
	{save=that;
	that=that->next;
	nachalo=that->begin;
	it=nachalo;
	menu2();
	that=save;		  }
}
void add_next()
{
	 if(Start_p==0)
		{
			 printf("You can't work without starting working\n");
		}

	else
	{    vneshni *save_that;
		if(first== NULL )// начала нет, следовательно нет и списка
		{
			first=(vneshni *)malloc (sizeof(vneshni));
			if(first== NULL)
			  printf("Memory for head of main list wasn't allocated\n");

			if(that == NULL)
			{
			 that=(vneshni *)malloc(sizeof(vneshni));
				if(that== NULL)
			   {
				 printf("Memory for main work pointer wasn't allocated\n");
				}
		   first->next=that;// создали начало списка и присоединили указатель на начало списка
		   that->next=NULL;
		   printf("Pervoe predlozhenie is added!!!Let's start work with it!!!\n");
			printf("Press \"Any Key\" to continue\n");
			getch();
			system("cls");
		   menu2();
			}
		 save_that=that;
		}

	   else if(that->next== NULL)// добавление предложения в конец списка
	   {  save_that=that;
		 that->next=(vneshni *)malloc(sizeof(vneshni));
			if(that->next== NULL)
			{
			  printf("Pamyat' ne videlilas!\n");
			}
		  that->next->next=NULL;
		  that=that->next;
		  //free(nachalo);//проблема здесь если зануляем указатели
		  //nachalo=NULL;//предложения, то вообще вся
		  //free(it);//предыдущая информация
		  //it=NULL;//пропадает
		 // that->begin=NULL;
		  nachalo=NULL;
		  it=nachalo;

		  printf("novoe predlozhenie sozdano!\n");
		   printf("Press \"Any Key\" to continue\n");
			getch();
			system("cls");
			menu2();
			that=save_that;
	   }

	  else if(that->next!=NULL)
	  {
		vneshni *novpr;
		   save_that=that;
		  novpr= (vneshni *)malloc(sizeof(vneshni));
			if(novpr== NULL)
			{
			 printf("Pamyat ne viidelilas'\n");
			 exit(0);
			}

		  novpr->next=that->next;
		  that->next=novpr;
		  that=that->next;
		  nachalo=NULL;
		  it=nachalo;
		  //free(nachalo);//проблема здесь, описана выше
		  //free(it);//проблема здесь
		  printf("Predlozhenie vstavleno\n");
		   printf("Press \"Any Key\" to continue\n");
			getch();
			system("cls");
			menu2();
			that=save_that;
	  }






   }

}
void print_all()
{   flag_print=1;
	if(Start_p==0 || is_empty()==1){

			if(Start_p==0)
			{
			 printf("You can't work without starting working\n");
			}
			else{
			 printf("List is empty\n");}
								  }

 else
 {
 vneshni *save_cur;
 vnutren *save_cur_slov;

	 /* save_cur=(vneshni *)malloc(sizeof (vneshni));
		if(save_cur == NULL)
		{
		 printf("Pamyat ne videlilas' for saving element for sentence!!!\n");
		}

	  save_cur_slov=(vnutren *)malloc(sizeof(vnutren));
		if(save_cur_slov == NULL)
		{
		  printf("Pamyat ne videlilas' for savin' element for word!!!\n");
		}
		  */
	  save_cur=that;// сохранили "координату" рабочего указателя (предложение)
	  save_cur_slov=it;// сохранили "координату" рабочего указателя(слово)


	  //that=first->next;// пришли на начало главного списка
	  //nachalo=that->begin;// пришли на начало предложения
	  //it=nachalo->next;
	   that=first->next;
	 while(that!=NULL)
	 {
		 if(that->begin == NULL  )
			that=that->next;
		   


		else
		{
		 if(save_cur == that)
		 {
			printf("[");
			print_one();
			printf("]");
			printf("\n");
		 }

		 else
		 {
		  print_one();
		  printf("\n");
		 }
		}

		 that=that->next;
		// nachalo=that->begin;
		 }
	   /*while(it->next!=NULL)  // пока не достигли конца предложения
	   {
		 if(it->next == NULL) // дошли до последнего слова
		 {
		  if(it == save_cur_slov )
		  {
			printf(" [%s] \n", it->c);
			//it=it->next;     // листаем дальше, по идее здесь мы в конце

			that=that->next;// перешли на следующее предложение
			it=that->begin->next;

		  }
		  else
		  {
		   printf(" %s \n", it->c);
		   //it=it->next;// достигаем конца предложения

		   that=that->next;// перешли на следующее предложение
		   it=that->begin->next;

		  }

		  /*if(it== NULL)
		   {
			that=that->next;// перешли на следующее предложение
			nachalo=that->begin;
			it=nachalo->next;
		   }
		  else
			printf("Konets ne dosstignut!!!!\n"); */
		/* }

		else
		{
		 if(it == save_cur_slov)
		   {
			printf(" [%s] ", it->c);
			it=it->next;
		   }
		 else
		   {
			printf(" %s ", it->c);
			it=it->next;
		   }
		}

	   } */


 that=save_cur;
 }
 flag_print=0;
 }
void end()
{



if(Start_p==1)
{

  empty();
  Start_p=0;
  Start_w=0;
  printf("We finished!\n");
 }
 else
   printf("You have to start work!\n");

}
/*
начать работу
сделать пустым
пустой ли?

указатель переместить на начало
указатель на начале?
передвинуть указ на след элемент
вывести элем после раб указателя
удалить элем после указателя
взять следующий элемент

изменить следующий элемент
добавить элем после указателя
распечатать весь список
ценок работы

фух
вроде все*/

void menu2(){
  int Select=0,flag=0;
  system("cls");
  printf("Chto vi hotite sdelat s predlozheniem?\n");
  printf("Choose your action:\n");
  printf(" 1.Start work\n 2.Make pledlozhenie empty\n 3.Is it empty?\n 4.Move pointer at the begining\n 5.Is the pointer on the begining?\n");
  printf(" 6.Is the pointer at the end of the sentence?\n 7.Move the pointer to the next element\n 8.Print element after the work pointer\n 9.Delete element after the work pointer\n 10.Take element after the work pointer\n");
  printf(" 11.Change the word after the work pointer\n 12.Add the word after the work pointer\n 13.Print one predlozh\n 14.Print all\n 15.Return back to main menu\n");
  scanf("%d", &Select);
		switch(Select){

			case 1: vnut_start();
					print_one();
					printf("\n");
					break;
			case 2: vnut_empty();
					print_one();
					printf("\n");
					break;
			case 3: if(Start_w==1){

					 if(vnut_is_empty()==1){
								  printf("Predlozhenie is empty\n");
					 }
					 if(vnut_is_empty()==0){
								  printf("Predlozhenie isn't empty\n");
					 }  }
					else
					  printf("You can't work without starting working\n");
					print_one();
					printf("\n");
					break;

			case 4: vnut_begin_predl();
					print_one();
					printf("\n");
					break;
			case 5: vnut_is_begin();
					print_one();
					printf("\n");
					break;
			case 6: vnut_is_end();
					print_one();
					break;
			case 7: vnut_next();
					print_one();
					printf("\n");
					break;
			case 8: vnut_print_next();
					print_one();
					printf("\n");
					break;
			case 9: vnut_delete_next();
					print_one();
					printf("\n");
					break;
			case 10: vnut_take_next();
					print_one();
					printf("\n");
					break;
			case 11: vnut_change_next();
					print_one();
					printf("\n");
					break;
			case 12:vnut_add_slovo();
					print_one();
					printf("\n");
					break;
			case 13: print_one();
					printf("\n");
					break;
			case 14: print_all();
					printf("\n");
					break;
			case 15: flag=1;
				 //  Start_w=0;	  //	main();
					break;
			default:
				printf("The Input is incorrect, try again\n");
				  break;

					}

		   printf("Press \"Any Key\" to continue\n");
	   getch();
		system("cls");
	 if(flag!=1)
		{ menu2();}

			  }

void vnut_start(void)
{

			 if(Start_w==0){

	   Start_w=1;
	   if (Start_w==1) {
	   printf("The work with predlozh can be started\n");

	   }
		}
	  else
	  {printf("You have already started work\n");
	  }

}

void vnut_empty(void){            //делает список пустым
				  vnutren *dilit, save_nachalo;
				  vneshni *del_that, *save;
				  del_that=(vneshni *)malloc(sizeof(vneshni*));
					  if(del_that == NULL)
					   printf("Deleting of whole sentence will not work\n");
				 // dilit=(vnutren*)malloc(sizeof(vnutren));
				 // if(dilit==NULL)
				//  printf("Udalenie ne proidet\n");

					if(Start_w==0 )
						{
						   printf("You can't work without starting working!\n");
						 }
		  else{
			   if(vnut_is_empty()== 0)  // все время удаляем начало
					{


						while(it!=NULL)
						{
						dilit=(vnutren*)malloc(sizeof(vnutren));
						if(dilit==NULL)
						printf("Deleting will not start!\n");

						it=nachalo;  // перешли в начало
						dilit=nachalo;
						it=it->next;
						nachalo=it;
						//nachalo->next=it->next;// начало- теперь это следующий
						free(dilit);
						//it=it->next;
						 }

					if(nachalo == NULL)      //  предложение удалилось, теперь и ссылку на него нужно удалить в главном списке
					{printf("Predlozhenie ochisheno!\n");
					 if(that== first->next)  // этот эксепшн надо обработать, если удаляем первое предложение, то тут два случая, если после него что то есть и если оно единственное
					 {
						del_that=that;//

						if(that->next == NULL)//кроме начала не было ничего
						{          // вообще тупо удаляем все
						 first->next= NULL;
						 free(del_that);
						 free(first);
						 first=NULL;
						 free(that);
						 that=NULL;
						}

						else    //
						{
						first->next=that->next->next;//указатель на первый становится указателем на второй
						free(del_that);
						}
					  }
					 else if(that!= first->next)// удаление предложения и сылки на него если оно не первое
					  {
						save=that;
						that=first->next;
						while(that->next!= save)//листаем до предыдущего
						 {that=that->next;

						  }
						nachalo=that->begin; // рабочие указатели переходят на предыдущий
						  it=that->begin;

						del_that=that->next;
						that->next=that->next->next;
						free(del_that);

					   that=first->next;//это новая деталь, после удаления предложения в середине рабочий указатель переходит в начало
					   nachalo=that->begin; // рабочие указатели переходят на предыдущий
					   it=that->begin;
					   it=nachalo;
                       //main();// нужно чтобы не торчать во внутреннем меню
					  }
					}
					else
					printf("Something went wrong with deleting!\n");
					}
				else
				printf("List is already empty!\n");
			  }
// that->begin=nachalo;//это для маркирования пустого в главном списке
}
int vnut_is_empty(void){

		 if(nachalo==NULL) //|| nachalo->next==NULL || that->begin == NULL){
		 {
			  return 1;//преджложение пусто возвращаем 1
		 }
		 else
			return 0;//предложение не пусто возвращаем 0

}

void vnut_begin_predl(void){

			   if(Start_w==0){
						  printf("You can't work without starting working\n");
							  }
			  else{
				   if(vnut_is_empty()==1)
							  printf("Predlozhenie is empty\n");
				   else
					  if(it==nachalo){
					  printf("Pointer is already on the begining!\n");

					  }
					  else{
					  it=nachalo;
					  printf("Predlozhenie na nachale!\n");
					  printf("[%s]\n", it->c);
					  }
			   }
}
void vnut_is_begin(void){
	if(Start_w==0 || vnut_is_empty()==1){

			if(Start_w==0)
			{
			 printf("You can't work without starting working\n");
			}
			else{
			 printf("Predlozhenie is empty\n");}
								  }
	 else{
		  if(it==nachalo)
			  printf("YES!\n");
		  else
			  printf("NO!\n");

	 }
}
void vnut_is_end(void)
{
   if(Start_p== 0 || vnut_is_empty()==1)
	{
	  if(Start_p== 0)
	   printf("You can't work without starting working\n");
	  else if(vnut_is_empty()==1)
	   printf("Begining doesn't exist. End doesn't exist.List is empty\n");
	}

   else
   {
   if(it->next == NULL || nachalo->next == NULL)
		   printf("YES! Pointer on the end!\n");

   else
		printf("Pointer not on the end!\n");
	}


}

void vnut_next(void){
		if(Start_w==0 || vnut_is_empty()==1){

			if(Start_w==0)
			{
			 printf("You can't work without starting working\n");
			}
			else{
			 printf("Predlozhenie is empty\n");}
								  }
		 else{


		  if(it->next!=NULL){
			//it=it->next; //передвинули указатель
			 printf("Pointer has been moved\n");
			 it=it->next;
			 printf("[%s]\n", it->c); //печатает лишь слово с рабочим указателем
							}

		  else
		   printf("Can't reach the element\n");
		  }

}

void vnut_print_next(void){


	if(Start_w==0 || vnut_is_empty()==1){

			if(Start_w==0)
			{
			 printf("You can't work without starting working\n");
			}
			else{
			 printf("Predlozhenie is empty\n");}
								  }
	  else{

			if(it->next!=NULL)
			{
				printf("[%s]\n", it->next->c);  //распечатали следующее слово
			}
			 else
				printf("The element can't be reached\n");
			}
}


void vnut_delete_next(void){
 vnutren *delet;  // нужен для удаления, для сохранения указательных полей для связок
  //vnutren *save;  // для возврата
			if(Start_w==0 || vnut_is_empty()==1){

			if(Start_w==0)
			{
			 printf("You can't work without starting working\n");
			}
			else{
			 printf("Predlozhenie is empty\n");}
								  }
			else{
				 delet=(vnutren*)malloc(sizeof(vnutren));
						if(delet==NULL){
						 printf("Necessary memory for \"delet\" wasn't allocated \n");
						  exit(0);
						}
				 // save=(vnutren*)malloc(sizeof(vnutren));
					   //	 if(save==NULL){
						//   printf("Necessary memory for \"save\" wasn't allocated \n");
						 // exit(0);
						  //	}


				if(it== that->begin)// удаление в начале
				{
				  delet=it->next; // присвоили следующий
				 // printf("Element [%s] is deleted\n", it->next->c);
				  it->next=it->next->next;
				  free(delet);
				  //delet=it;       //это еси удаляем 1-ый элемент
				  //it=it->next;
				  //nachalo->next=it;
				  //free(delet);
				  print_one();
				}
				else if(it->next == NULL)
				{
				   printf("Can't reach the element, sorry\n");
				}
				else if(it->next->next == NULL) //удаление в конце
				{
				  delet=it->next;
				 // printf("Element [%s] is deleted\n", it->next->c);
				  it->next= NULL;
				  free(delet);
				  print_one();
				}
				else if(it->next->next != NULL) // удаление в середине
				{
				  delet=it->next;
				 // printf("Element [%s] is deleted\n", it->next->c);
				  it->next=it->next->next;
				  free(delet);
				  print_one();
				}


				else
				 printf("Something went wrong!!!!");
		   //	free(delet);  // освободили память
		   //	free(save);   // освободили память
			}
}
void vnut_take_next(void)
{
  vnutren *delet;  // нужен для удаления, для сохранения указательных полей для связок
  vnutren *save;  // для возврата
			if(Start_w==0 || vnut_is_empty()==1){

			if(Start_w==0)
			{
			 printf("You can't work without starting working\n");
			}
			else{
			 printf("Predlozhenie is empty\n");}
								  }
			else{
				 delet=(vnutren*)malloc(sizeof(vnutren));
						if(delet==NULL){
						 printf("Necessary memory for \"delet\" wasn't allocated \n");
						  exit(0);
						}
				  save=(vnutren*)malloc(sizeof(vnutren));
						 if(save==NULL){
						   printf("Necessary memory for \"save\" wasn't allocated \n");
						  exit(0);
							}


				if(it== that->begin)// удаление в начале
				{
				  delet=it->next; // присвоили следующий
				  printf("Taken Element [%s] is deleted\n", it->next->c);
				  it->next=it->next->next;
				  free(delet);
				  //delet=it;       //это еси удаляем 1-ый элемент
				  //it=it->next;
				  //а если кроме начала ничего нет то free(it);
				  //nachalo->next=it;
				  //free(delet);
				}
				else if(it->next->next == NULL) //удаление в конце
				{
				  delet=it->next;
				  printf("Taken Element [%s] is deleted\n", it->next->c);
				  it->next= NULL;
				  free(delet);

				}
				else if(it->next->next != NULL) // удаление в середине
				{
				  delet=it->next;
				  printf("Taken Element [%s] is deleted\n", it->next->c);
				  it->next=it->next->next;
				  free(delet);
				}
				else if(it->next == NULL)
				{
				   printf("Can't reach the element, sorry\n");
				}

				else
				 printf("Something went wrong!!!!");
		   //	free(delet);  // освободили память
		   //	free(save);   // освободили память
			}






}
void vnut_change_next(void){
  //int i=0;// мдаа......
  //char c[20];// для редактирования слова берем новый массив, в него вводим новые символы
  vnutren *save;
				 save=it;
  if(Start_w==0 || vnut_is_empty()==1){

			if(Start_w==0)
			{
			 printf("You can't work without starting working\n");
			}
			else{
			 printf("Predlozhenie is empty\n");}
								  }

  else{
		 save=(vnutren *)malloc(sizeof(vnutren));// выделили память под текущий указатель
								  if(save==NULL){
									printf("Memory for \"Save \" wasn't allocated\n");
									   exit(0); }

	  printf("The element [%s] will be changed\n", it->next->c);
	  printf("Input new version:\n");

	  //free(it->next->c);

      
	  scanf("%s", &it->next->c);

	  printf("\n");
	  printf("The element is edited:[%s] \n", it->next->c);// напечатали новый структурный массив, уже измененный
	  it=save;
	  }

}
// добавить фуекцию указываем ли на конец?
void vnut_add_slovo(void){
	if(Start_w==1){
			   vnutren* save_cur;
			 if( vnut_is_empty()==1) // нет начала предложения
			   {
				 nachalo=(vnutren *)malloc(sizeof(vnutren));
					 if(nachalo==NULL)
					 {
					 printf("Memory for nachalo ne videlilas! \n");
						 exit(0);
						 }


			  /*else	if(nachalo->next == NULL)//в предложении есть только одно начало
			   {    */
				  if(it==NULL)// начало есть но лругих элементов и рабочего указателя нет
				  {
					it=(vnutren *)malloc(sizeof(vnutren));

						 if(it==NULL){
							printf("Memory for rabochii pointer ne videlilas!\n");
							exit(0);
									}
				  }

					printf("Vvedite slovo:\n");
					scanf("%s", nachalo->c);
					if(nachalo->c!=NULL)
						{
						printf("The word [%s] was added!\n" , nachalo->c);
						it=nachalo;
						nachalo=it;// сохранили начало предложения в перем. nachalo->next
						that->begin=nachalo;// важно поле данных глав. списка- это начало предложения
						it->next=NULL;//it=it->next;

						col++;
						 save_cur=it;
						 }
				   else
						printf("Something went wrong with adding the worn in the beginning!\n");
				//}
						 }

			  else if(it->next == NULL)  // добавление в конец списка
			  {    save_cur=it;
				// it=it->next; // мы в конце списка
				 it->next=(vnutren *)malloc(sizeof (vnutren));
						if(it->next == NULL)
						{ printf("Memory for new word wasn't allocated!!\n");
						}
				  printf("Vvedite slovo na konets:\n");
				  scanf("%s", &it->next->c);

					 it->next->next=NULL;// новый конец списка за следующим элементом
				   if(it->next->c != NULL)
				   {
					 printf("The word [%s] was added!\n", it->next->c);
					 col++;
				   }
				   else
				   {
					printf("Something went wrong with adding the word at the ending!\n");
				   }
			   //	it=it->next;
			  }

			  else if(it->next!= NULL)//добавление в середину
			  {
				vnutren *new_el;
				save_cur=it;
				   new_el=(vnutren *)malloc(sizeof(vnutren));
					   if(new_el==NULL)
					   {
						 printf("Memory for new word wasn't allocated!!\n");
					   }
				   printf("Vvedite novoe slovo (v seredinu)\n");
				   scanf("%s", new_el->c);

				   if(new_el->c!= NULL)
				   {
					printf("The word [%s] was added!\n", new_el->c);
					col++;
				   }
				   else
				   {
					printf("Something went wrong with adding the word at the middle!\n");
				   }

					new_el->next=it->next;         //

					it->next=new_el;
				   printf("new word is [%s]\n", it->next->c);
				   }
it=save_cur;
}}
void print_one(void)
{  if(Start_w == 1 && vnut_is_empty() == 0 )

   {
		 vnutren *save;
		 /*if(save == NULL)
		 {
		 save=(vnutren*)malloc(sizeof(vnutren));
			if(save==NULL){
			  printf("Neccessary memory for \"save\" wasn't allocared");
			  exit(0);
						  }
		 }*/
		   save=it;// save the begining of the sentence

		   nachalo= that->begin;
		   it=nachalo;

		   while(it!=NULL)
		   {    if (flag_print==0)
				{

				if(it==save)
				{
					if(it->next!=NULL)
						printf("[%s]", it->c);
					else
						{printf("[%s]", it->c);
						//printf("----------------------------------------------------\n");
						 }
				}
				else
				{
					if(it->next!=NULL)
					printf(" %s ", it->c);

					else
					{printf(" %s", it->c);
					//printf("----------------------------------------------------\n");
					}
				}
				}
				else
				{
					if(it->next!=NULL)
					printf(" %s ", it->c);

					else
					{printf(" %s", it->c);
					//printf("----------------------------------------------------\n");
					}
				}
		   it=it->next;


		   }
		   it=save;
		   //printf("\n");
		   //free(save);
	}

	else
	{
	   if(Start_w== 0)
	 printf("You can't work without starting work\n");
	   else if(vnut_is_empty()== 1) // если предложение пусто
	   {
		 printf("Your list is empty.I can't print it!\n");

	   }
	 //printf("Your list is empty.I can't print it!\n");
		//that=that->next;
	   // print_one();
	 }
}




/* struct vneshni{// внешняя структура для переключения предложений
   struct vnutren *begin;//"как бы поле данных", здесь хранятся начала внутрених структур-списков (односвяз.)
   struct vnesh *next;// поле-указатель на след. элемент
};

	struct vnutren{// внутренний односвязный список (предложение)
	struct vnutren *next;//поле указатель на след. символ
	char c;// поле данных- символ
}; */

				   /* i=0; //блок считывания
			 while(i<20){

			 if(c[i]=='\n' || c[i]==' ' || i>=20)
			   break;

			 else{
			 while(i<20 && c[i]!='\n' && c[i]!=' ') // записали массив в новую структуру
			 {add->c[i]=c[i];
			 i++;}
				  }
				  } //блок считывания  */




















												   /*  if(it==NULL){   // если нет рабочего указателя в предложении
			 it=(vnutren *)malloc(sizeof(vnutren));

			 if(it==NULL){
			 printf("Memory for \"it\" wasn't allocated! \n");
				exit(0);
			 }
			 }





		 if(Start_w==0){
		 printf("You can't work without starting working\n");
					   }
		else {

			 if(it==NULL){   // если нет рабочего указателя в предложении
			 it=(vnutren *)malloc(sizeof(vnutren));

			 if(it==NULL){
			 printf("Memory for \"it\" wasn't allocated! \n");
			   // exit(0);
			 }
			 }

			 if(nachalo== NULL){
			 nachalo=(vnutren *)malloc(sizeof(vnutren));
					if(nachalo== NULL){
					printf("Memory for nachalo wasn't allocated\n");
					}
								}

		if(first==NULL || vnut_is_empty()==1){   // если нет начала главного списка
			 first=(vneshni*)malloc(sizeof(vneshni));
			 if(first==NULL)
			 {printf("First doesn't exist\n");
			 //exit(0);
			 }
			 if(first->begin== NULL ){
			 first->begin=(vnutren *)malloc(sizeof(vnutren));// создали начало для главного списка

			 if(first->begin== NULL){
			 printf("First->begin doesn't exist\n");
			 //exit(0);


			 }
			 else{

				printf("Enter word\n");
				scanf("%s",&first->begin->c);
				first->begin->next=NULL;
				it=first->begin;//
				it->next=NULL;//создано начало списка предложения и рабочий на нем
				nachalo=first->begin;
				nachalo->next=it->next;
				printf("word [%s] is added\n", nachalo->c);

				  }
									   }
		}

		else if(it->next==NULL){

			   it->next=(vnutren *)malloc (sizeof (vnutren));
			   if (it->next==NULL)
				printf("Memory wasn't allocated\n");
			else
			{
				printf("Enter word\n");
				scanf("%s",&it->next->c);
				it->next->next=NULL;

				printf("Word [%s] is added\n", it->next->c);
			}
		 }

		 else if(it->next!=NULL){

			vnutren *newel;
			newel=(vnutren *)malloc (sizeof (vnutren));
			   if (newel==NULL)
				printf("Память не выделилась\n");
			else
			{
				printf("Enter word\n");
				scanf("%s",&newel->c);
				newel->next=it->next;
				it->next=newel;

				printf("Слово [%s] добавлено\n", it->next->c);
			}
		 }

		 else
			 printf("There is no situations\n");
		 printf("\n");
		}

}

		   /*     printf("Enter new word:\n");
			 scanf("%s", &add->c);  // занесли массив в структуру   */

			   /*    if(add==NULL){
					printf("Memory for new slovo wasn't allocated! \n");
							}
		else{

				if(first->begin== NULL || vnut_is_emty()==1){ // предложение пусто// добавление в начало предложения

								nachalo=(vnutren *)malloc(sizeof(vnutren));  // выделили память под начало
									if(nachalo==NULL){  // если нет начала, под него не выделилась
									printf("Memory for \"nachalo\" wasn't allocated  \n");
									exit(0);
													}

								add->next=NULL;// указатель начала- НУЛЛ
								nachalo=add;// присвоили начало
								nachalo->next=NULL; // указатель начала- НУЛЛ
								//nachalo->next=it;  // рабочий стал следующим после неачала
								it=nachalo;
								it->next=NULL;

										if(first==NULL){   // если начала не было
											first=(vneshni *)malloc(sizeof (vneshni));
												if(first==NULL){
													printf("Memory for \"first\" wasn''t allocated \n");
														exit(0);
																}
															first->begin= nachalo;// занесли начало 1-го предложения в начало переключателя
																first->next= NULL;
																that= first;
																}

								printf("Element [%s] was added!!!\n", nachalo->c);
								free(add);  //не обязательно
										}

				else if(it->next== NULL ){ // добавление в конец предложения

								  add->next=NULL;
								  it->next=add;
								  it=it->next;
								  it->next=NULL;
								  printf("The Element [%s] was added\n", it->c);
								  free(add);
							   }

				else if(it->next!=NULL){// добавление в общем случае (не в конец и не в начало)


									   add->next=it->next;// берем указательное поле текущего которое указывает на следующий элемент
									   it->next=add;//
									   it=it->next;
									   printf("The Element [%s] was added\n", it->c);
									   free(add);
												}

								   }

						  }

				}*/   /*		 if( vnut_is_empty()==1 ) // нет начала предложения
			   {
				 nachalo=(vnutren *)malloc(sizeof(vnutren));
					 if(nachalo==NULL){
					 printf("Memory for nachalo ne videlilas! \n");
						 exit(0);
					 }

			   // есть вариант что элс иф должен быть просто ифом в ветке начало== НУЛЛ
			  else	if(nachalo!= NULL && nachalo->next== NULL)//в предложении есть только одно начало
			   {
				  if(it==NULL)// начало есть но лругих элементов и рабочего указателя нет
				  {
					it=(vnutren *)malloc(sizeof(vnutren));

						 if(it==NULL){
							printf("Memory for rabochii pointer ne videlilas!\n");
							exit(0);
									}
						}

					printf("Vvedite slovo:\n");
					scanf("%s", &it->c);
					if(it->c!=NULL)
						{
						printf("The word [%s] was added!\n" , it->c);
						nachalo->next=it;// сохранили начало предложения в перем. nachalo->next
						that->begin=nachalo;// важно поле данных глав. списка- это начало предложения
						it->next=NULL;
						}
				   else
						printf("Something went wrong with adding the worn in the beginning!\n");
						}
			   }
			  else if(it!= NULL && it->next == NULL)  // добавление в конец списка
			  {
				 it=it->next; // мы в конце списка
				 it=(vnutren *)malloc(sizeof (vnutren));
						if(it == NULL)
						{ printf("Memory for new word wasn't allocated!!\n");
						}

				 it->next=NULL;// новый конец списка за следующим элементом
				  printf("Vvedite slovo:\n");
				  scanf("%s", &it->c);

				   if(it->c != NULL)
				   {
					 printf("The word [%s] was added!\n", it->c);
				   }
				   else
				   {
					printf("Something went wrong with adding the word at the ending!\n");
				   }
			  }

			  else if(it!=NULL && it->next!= NULL)//добавление в середину
			  {
				vnutren *new_el;
				   new_el=(vnutren *)malloc(sizeof(vnutren));
					   if(new_el==NULL)
					   {
						 printf("Memory for new word wasn't allocated!!\n");
					   }
				   printf("Vvedite novoe slovo\n");
				   scanf("%s", &new_el->c);

				   if(new_el->c!= NULL)
				   {
					printf("The word [%s] was added!\n", it->c);
				   }
				   else
				   {
					printf("Something went wrong with adding the word at the middle!\n");
				   }

				   it->next=new_el;
				   new_el->next=it->next->next;
				   //free(new_el);
				   }         */
				 /*		  if(first->begin == NULL)
				  {
				   first->begin=(vnutren *)malloc(sizeof(vnutren));
					  if(first->begin == NULL)
					   {printf("Memory for begining wasn't allocated\n");
						   exit(0);
					   }
					  else
						{
						 printf("Enter first word\n");
						 scanf("%s", &first->begin->c);
						 first->begin->next=NULL;
						 it=first->begin;
						 printf("Slovo [%s] is added\n", it->c);
						}

				  }

				  else if(it->next == NULL)
				  {
				   it->next=(vnutren *)malloc(sizeof(vnutren));
						 if(it->next== NULL)
						 {
						  printf("Memory for new slovo ne videlilas!\n");
						 }
						 else
						 {
						  printf("Enter new slovo\n");
							scanf("%s",&it->next->c);
							it->next->next=NULL;
							//endpr=rabpr->nextpr;
							printf("Word [%s] added\n", it->next->c);
							}
				  }

				  else if(it->next!= NULL)
				  {
				   vnutren *new_el;
					new_el=(vnutren *)malloc(sizeof(vnutren));
					  if(new_el==NULL)
					  {
					   printf("Memory nevidelilas\n");

					  }
					  else
					  {
						printf("Vvedite slovo\n");
						scanf("%s", &new_el->c);
						new_el->next=it->next;
						it->next=new_el;
						printf("word [%s] added", it->next->c);
					  }
				  }
				  else
					printf("Something went wrong!!!!!\n");

  }
   else
	 printf("You must start working before choosing this\n");
   */








   /*	  if(it->next== NULL ){
				   printf("You are n the end of the sentence.Can't go further\n");
				  }
				  else if(it->next->next!= NULL){}

				  if(it->next->next==NULL){   //для предпоследнего элемента, удаление последнего
				   save=it;// сохранили адрес элемента, предшествующего удаляемому

				   delet=it->next;  //сохранили адресное поле удаляемого элемента
				   printf("The element [%s] was succesfully deleted\n", delet->c);
				   free(delet);//освободили память уже текущего

				   it->next=NULL;

				  }
				  else if(it->next->next)
					printf("The element can't be reached\n");
				 */







									/*  if(it== nachalo->next && it->next== NULL) //если указатель на начале
					  {
						dilit= nachalo->next;
						nachalo->next=NULL;
						free(dilit);

						}

					 else
					 { it=nachalo->next;

					   while(it->next !=NULL)
					   vnut_delete_next();



					 }



					  nachalo=NULL; // занулили и начало, сделав список по-настоящему пустым
					  system("cls");
					  if(it==NULL && nachalo== NULL)
					  printf("Predlozhenie is empty!\n");

					}}
				//else
				  // printf("Your predlozhenie is already empty!\n");

			  }

//} */                                      /*        else{

						 it=nachalo;
							   while(it->next!=NULL){
									 dilit->next=it->next;  //сохранили указательное поле удаляемого
									 free(it);       // освободили память
									 it=dilit->next;  //передвинулись по сохраненному адресу
								  }
						 nachalo=NULL;

						if(it==NULL){

							  printf("Predlozhenie is empty\n");
									 }
					   else
							printf("Predlozhenie udalit' ne udalos'\n");
						}

						}
					else
					  printf("You can't work without starting working\n"); */







/*

		that=that->next; // передвинули указатель рабочий на след предложение
		delet->next=that->next; //  сохранили указательное поле удаляемого
		   that=first;
		   while(delet->next!=that->next) // пока не дошли до предыдущего нового
		   {that=that->next;
		   }
		   that->next=delet->next;
		   free(delet);
		   printf("element has been deleted\n");
		//it=that->begin;// перешли на начало предложения
		//нужно переделать связи между элементами переключателя

				  /* while(it->next!=NULL)// пока не конец предложения
					{  //тупо всю структупу удалить
					  free(it->c);  //освободили слово
					  it=it->next; // идем к следующему

					}*/
		   //	   }

//}//вернуться к функции удаления позже
