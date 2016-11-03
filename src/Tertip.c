//Adem Kerenci
//Bekir Zahit Demiray
//Muhammed Ali Sit

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int i;


//printf("\033[2J\033[1;1H");

//defince functions
void create_file();
void delete_file();
void rename_file();
void copy_file();
void move_file();
void textfile();
void append_text();
void insert_text();
void remove_content();
void show_content();
void help_();

//main function
void main()
{
    int exit=0 ,choice;


    //list all options
    while (exit==0)

    {

        printf("\033[2J\033[1;1H");
        printf("\nWhat do you want to do?\n");

        printf("\n1-)Create a File\n");

        printf("2-)Delete a File\n");

        printf("3-)Rename a File\n");

        printf("4-)Copy a File\n");

        printf("5-)Move a File\n");

        printf("6-)Text file menu\n");

        printf("7-)Help\n");

        printf("8-)Exit\n");

        printf("Your choice?\n");
        scanf("%d",&choice);

        switch(choice)
        {
            case 1:
                create_file();
                break;
            case 2:
                delete_file();
                break;
            case 3:
                rename_file();
                break;
            case 4:
                copy_file();
                break;
            case 5:
                move_file();
                break;
            case 6:
                textfile();
                break;
            case 7:
                help_();
                break;
            case 8:
                printf("Program is closed, Bye Bye:)\n");
                exit++;
                break;
            default:
                printf("Your choice isn't in the menu:( \n");
                break;
        }


    }



}


// function to create file
void create_file()
{
    printf("\033[2J\033[1;1H"); //Clean the screen
    // define vars
    FILE *new_file;
    char nfile_name[30];
    i=0;
    int k;
    while(i==0)
    {
        printf("Please enter a name(max30) for file:\n");
        scanf("%s",nfile_name);// take the filename
    if (access(nfile_name, 0) ==0)// Check if the file is exist or not
    {
        //if it exists
        printf("You have a file with same name.\n");
        printf("Press 1 to try with another name.\n");
        printf("Press another number to go back previous menu:\n");
        //ask to user what to do
        scanf("%d",&k);
        if(k!=1)
            return;//get out function
    }
    else
        i=1;//get out while loop
    }

    // if file is not exist
    new_file = fopen(nfile_name,"w+"); //  Open the file
    fclose(new_file);
    printf("%s was created successfully.\n",nfile_name);
    printf("Press 1 to recreate another file.\n");
    printf("Press another number to go back main menu:\n");
    // ask user to what to do
    scanf("%d",&i);

    if (i==1)
        create_file();//recall function



}



// function to delete file
void delete_file()
{
    printf("\033[2J\033[1;1H");//Clean the screen
    // define vars
    char deleted_name[30];
    int deleted;

    printf("Please enter the name you want to delete:\n");
    scanf("%s",deleted_name);//take the file name you want to delete

    //delete the file
    deleted=remove(deleted_name);

    if (deleted==0) // if file is deleted
    {
        //print results of process
        printf("%s was successfully deleted.\n",deleted_name);
        printf("Press 1 to delete another file..\n");
        printf("Press another number to go back main menu:\n ");
        //ask the user what to do
        scanf("%d",&i);

        if (i==1)//recall the function
            delete_file();

    }
    else  //if the file doesn't exist
    {
        printf("There is no %s.\n",deleted_name);
        printf("Press 1 to try again with different name.\n");
        printf("Press another number to go back main menu:\n ");
        scanf("%d",&i);

        if (i==1)//recall the function
            delete_file();
        }
}



//file renaming function
void rename_file()
{
    printf("\033[2J\033[1;1H");
    //define vars
    int out=0;
    char new_name[30],old_name[30];


    printf("Please enter the file name you want to change:\n");
    scanf("%s",old_name); //take the file name

    // check if the file exists
    while (access(old_name, 0) !=0 )
        {//if not exist
        printf(" %s isn't exist.Please 1 to try again.\n",old_name);
        printf("Press another number to go back previous menu:\n");
        //ask user what to do
        scanf("%d",&i);
        if (i!=1)
            return;
        printf("Please enter a file name:\n");
        scanf("%s",old_name);

        }
    // ask for new name
    printf("Please enter file name you want to use:\n");
    scanf("%s",new_name);
    while (access(new_name, 0) ==0 )//if it does exist
    {
        //ask user what to do next
        printf("%s is already exist.\n",new_name);
        printf("Press 1 to write new name.\n");
        printf("Press another number to go back main menu.\n");

        scanf("%d",&i);
        if (i==1)
        {   //take new file name
            printf("Please enter a file name:\n");
            scanf("%s",new_name);
        }
        else//else, exit
            return;

    }
    rename(old_name, new_name);//change the name with new one
    printf("%s successfully change to %s",old_name,new_name);


}



//file copying function
void copy_file()
{
    //define vars
    int k=0;
    printf("\033[2J\033[1;1H");
    FILE *source_file,*target_file;
    char ch,source_name[128],target_name[128];
    while(k==0)
    {
    printf("Please enter the name you want to copy:\n");
    scanf(" %[^\n]s ",source_name); //take the file that user want to copy
    if (access(source_name, 0) !=0)
        {// if it doesn't exist
            printf("%s isn't exist.",source_name);
            printf("Press 1 to try again\n");
            printf("Press another number to go back main menu:\n");
            scanf("%d",&i);//ask user what to do
            if (i!=1)
                return;
        }
    else
        k=1;
    }
    while(k==1)
    {//ask for new name for copied file
        printf("Please enter name to copy file:\n");
        scanf(" %[^\n]s ",target_name);
        if (access(target_name, 0) ==0)//check if a file with new name exists
        {
            printf("%s is exist.",target_name);
            printf("Press 1 to try again\n");
            printf("Press another number to go back main menu:\n");
            scanf("%d",&i);//ask user what to do
            if (i!=1)
                return;
        }
    else
        k=2;
    }
    // take files
    source_file=fopen(source_name,"rb");
    target_file=fopen(target_name,"wb");
    while( ( ch = fgetc(source_file) ) != EOF )//copy a character from source to destination file in each iteration
    {
        fputc(ch, target_file);
    }

    //close files
    fclose(source_file);
    fclose(target_file);
    printf("Data copy from %s to %s\n",source_name,target_name);
    printf("Press 1 to recopy a file\n");
    printf("Press another number to go back main menu:\n");
    scanf("%d",&i);//ask user what to do

    if (i==1)
        copy_file();// recall the function



}


//file moving function
void move_file()//error in space
{
    //define vars
    int k=0;
    FILE *source,*target;
    char ch,file_name[30];
    char source_path[1024],target_path[1024];


    while(k==0)
    {// take the file name from user
    printf("Please enter file name you want to move:\n");
    scanf("%s",file_name);
    printf("Please enter %s path:\n",file_name);
    //take the file's path
    scanf(" %[^\n]s ",source_path);
    //combine them to have full path of the file
    strcat(source_path,file_name);

    // check if the file exists
    if (access(source_path, 0) !=0)
        {//if it's not exist
            printf("%s isn't exist.",file_name);
            printf("Press 1 to try again\n");
            printf("Press another number to go back main menu:\n");
            scanf("%d",&i); // ask user what to do
            if (i!=1)
                return;
        }
    else
        k=1;
    }


    while(k==1)
    {
        printf("Please enter the destination path:\n");//take destination path
        scanf(" %[^\n]s ",target_path);
        //combine the filename and the dest name
        strcat(target_path,file_name);
        //if file exists
        if (access(target_path, 0) ==0)
        {//file is exist
            printf("%s is exist.",file_name);
            printf("Press 1 to try again\n");
            printf("Press another number to go back main menu:\n");
            scanf("%d",&i);//ask user what to do
            if (i!=1)
                return;
        }
    else
        k=2;
    }

    //open files
    source=fopen(source_path,"r");
    target=fopen(target_path,"w");



    //copy a character from source to destination file in each iteration
    while((ch=fgetc(source))!=EOF)
            {
                fputc(ch,target);
            }

    //close the files
    fclose(source);
    fclose(target);

    //remove source file
    remove(source_path);
    printf("%s was moved successfully.\n",file_name);
    printf("Press 1 to move another file.\n");
    printf("Press another number to go back main menu:\n");
    scanf("%d",&i);
    if (i==1)//ask user what to do
        move_file();

}



//text menu function
void textfile()
{
    int text_choice;
    int temp_exit=0;
    while(temp_exit==0)
    {
        // list options
    printf("What do you want to do?\n");
    printf("\n1.Append Text\n");

    printf("2.Insert Text\n");

    printf("3.Remove text\n");

    printf("4.Show Content\n");
    printf("5.Return the main menu:\n");

    //ask user to choose one of the options
    scanf("%d",&text_choice);

    // check which option is chosen
    switch(text_choice)
    {
        case 1:
            append_text();
            break;

        case 2:
            insert_text();
            break;
        case 3:
            remove_content();
            break;
        case 4:
            show_content();
            break;
        case 5:
            temp_exit=1;//break the loop n get back to previous menu
            break;
        default:
            printf("Please choose correct\n ");
            break;
    }
}

}


// text append function
void append_text()
{
    //define vars
    int k=0;
    FILE *edited_file;
    char file_name[30];
    char appending_text[300];
    while (k==0)
    {
        //take the file name
        printf("Please enter name of the file you want to append text:\n");
        scanf(" %[^\n]s ",file_name);

        //check if it exists
        if (access(file_name, 0) !=0)//Check file is exist
    {//if it doesn't exist
        printf("%s doesn't exist.\n",file_name);
        printf("Press 1 to enter a new name.");
        printf("Press another number to go back previous menu:\n");
        scanf("%d",&i);
        if(i!=1)//ask user what to do
            return;
    }
        else
            k=1;

    }
    //ask for the text that user wants to append
    printf("Please enter the text (max.300) you want to append:\n");
    scanf(" %[^\n]s ",appending_text);//white space work

    //open the file
    edited_file=fopen(file_name,"a+");
    //append the text
    fputs(appending_text,edited_file);


    printf("Your text added into %s.\n",file_name);
    //close the file
    fclose(edited_file);
    printf("Press 1 to append another text.");
    printf("Press another number to go back previous menu:\n");
    scanf("%d",&i);//ask user what to do
    if(i==1)
        append_text();

}


//removing content function
void remove_content()
{
    //define vars
    FILE *file;
    char file_name[30];
    i=1;
    while(i==1)
    {
        // take the file name
        printf("Please enter the file name to delete content of it: \n");
        scanf("%s",file_name);
        //check if the file exists
        if (access(file_name, 0) !=0)//Check file is exist
    {
        //it's not exist
        printf("%s doesn't exist.\n",file_name);
        printf("Press 1 to enter a new file name.");
        printf("Press another number to go back previous menu:\n");
        scanf("%d",&i);//ask user what to do
        if(i!=1)
            return;
    }
        else
            i=0;

    }
    //if file exists open the file with write mode to remove all the content in it
    file=fopen(file_name,"w+");
    //close the file
    fclose(file);
    printf("%s's content was deleted successfully.\n ",file_name);
    printf("Press 1 to recall this function\n");
    printf("Press another number to go back previous menu:\n ");
    scanf("%d",&i);//ask user what to do next
    if (i==1)
        remove_content();
}



//content showing function
void show_content()
{
    //define vars
    FILE *file;
    char ch,file_name[30];
    int line_number,temp_lnumber=0;
    i=1;
    int page_number=1;
    int next;

    while(i==1)
    { // ask for file name
        printf("Please enter the file name to show content of it: \n");
        scanf("%s",file_name);
        if (access(file_name, 0) !=0)//Check file is exist
    {   //if it doesn't exist
        printf("%s doesn't exist.\n",file_name);
        printf("Press 1 to enter a new file name.");
        printf("Press another number to go back previous menu:\n");
        scanf("%d",&i);
        if(i!=1)//ask user what to do
            return;
    }
        else
            i=0;
    }

    //ask for the line number to show
    printf("Please enter line number to show:\n");
    scanf("%d",&line_number);

    //if the number lower than 1, exit
    if (line_number<1)
        return;

    //otherwise, open the file
    file=fopen(file_name,"r+");


    while((ch=fgetc(file))!=EOF)
    {
                printf("%c",ch);

                if(ch == '\n' &&  ++temp_lnumber == page_number*line_number)//increase the temporary line number when it sees new line character
                    {page_number++;//increase the page number
		    printf("Please press 1 to next page:");//ask user if he/she wants to go next page
		    scanf("%d",&next);
		    if (next!=1) break;
		}
    }

    printf("\nPress 1 to enter a new file name:\n");
    printf("Press another number to go back previous menu:\n");
    scanf("%d",&i);//ask user what to do
    if(i==1)
        show_content();
}


//text inserting function
void insert_text()
{
    //define vars
  FILE *file,*file_temp;
  char ch,file_name[30],inserting_text[300],temp_file[30];
  int ch_number,temp_ch=0,total_ch=0;
  int k;
  i=1;
    while(i==1)
    {   // take file name
        printf("Please enter the file name to insert text: \n");
        scanf("%s",file_name);

        if (access(file_name, 0) !=0)//Check file is exist
    {//if doesn't exist
        printf("%s doesn't exist.\n",file_name);
        printf("Press 1 to give a another file name.");
        printf("Press another number to go back previous menu:\n");
        scanf("%d",&k);//ask user what to do
        if(k!=1)
            return;
    }
        else
            i=0;
    }
    // if file exist, continue
    while(i==0)
    {
        printf("Please enter the file name different than your files: \n");
        scanf("%s",temp_file);//ask for new name to store the temporary text

        if (access(temp_file, 0) ==0)//Check file is exist
    {
        //if exists, raise error
        printf("%s  exist.\n",file_name);
        printf("Press 1 to give a another file name.");
        printf("Press another number to go back previous menu:\n");
        scanf("%d",&k);//ask user what to do
        if(k!=1)
            return;
    }
        else
            i=1;
    }

    //open the file
    file=fopen(file_name,"r");

    //calculate the total number of chars in file
    while((ch=fgetc(file))!=EOF)
    {
                total_ch++;
    }

    //close the file
    fclose(file);
    //take the text that will be inserted
    printf("Please enter the text (max.300) you want to append:\n");
    scanf(" %[^\n]s ",inserting_text);
    printf("%s\n",inserting_text);
    while(i==1)
    {
        printf("Please enter the position:\n");//ask the position to insert
        scanf("%d",&ch_number);
        if (ch_number>total_ch)//if the given position is beyond the length of the file, raise error
        {
            printf("Given position is larger than total characters.\n");
            printf("Press 1 to give another position.\n");
            printf("Press another number to go back previous menu:\n");
            scanf("%d",&i);//ask user what to do
            if(i!=1)
                return;
        }
        else
            i=0;
    }

    //open files
    file=fopen(file_name,"r");
    file_temp=fopen(temp_file,"w");

    //insert the text from original file to temporary file to store it
    while((ch=fgetc(file))!=EOF)
    {
        if(temp_ch==ch_number)// when you reach the given index, append the text
            fputs(inserting_text,file_temp);
        fprintf(file_temp,"%c",ch);
        temp_ch++;

    }

    //close files
    fclose(file);
    fclose(file_temp);

    //open files
    file_temp=fopen(temp_file,"r");
    file=fopen(file_name,"w");

    //insert the text from temporary file to intended file
     while((ch=fgetc(file_temp))!=EOF)
    {

        fprintf(file,"%c",ch);

    }

    //close files
    fclose(file_temp);
    fclose(file);

    //remove temp file
    remove(temp_file);
    printf("Please enter 1 to recall function.\n");
    printf("Please enter another  number to go back previous menu:\n");
    scanf("%d",&i); // ask user what to do
    if(i==1)
        insert_text();


}


// help function
void help_()
{
    //define vars
    char choice_help[30];
    int k=0;
    while(k==0)
    {
        //ask user to choose sth
    printf("Please enter subject:\n");
    scanf(" %[^\n]s ",choice_help);

    if (strcmp(choice_help,"create /h") == 0)
        printf("You should give a unique file name to create a file.\n");

    else if (strcmp(choice_help,"delete /h")==0)
        printf("You should give a file name to delete file.\n");
    else if (strcmp(choice_help,"rename /h")==0)
        printf("You should give a name different than your other file.\n");
    else if (strcmp(choice_help,"copy /h")==0)
        printf("You should give a source file name and target file name.\nTarget file name should be different than other files.\n");
    else if (strcmp(choice_help,"move /h")==0)
        printf("You should give a file name, path of file and target path.\n");
    else if (strcmp(choice_help,"append /h")==0)
        printf("You should give a file name and text to append.\n");
    else if (strcmp(choice_help,"insert /h")==0)
        printf("You should give a file name, position, another file name to use in progress and text to insert.\n");
    else if(strcmp(choice_help,"remove")==0)
        printf("You should give a file name.\n");
    else if(strcmp(choice_help,"show /h")==0)
        printf("You should give a file name and line number to how many line you want to see.\n");
    else
        printf("You give a wrong statement.\n");
    printf("Press 1 to go back previous menu:\n");
    scanf("%d",&i);//ask user what to do next
    if (i==1)
        k=1;

    }


}
