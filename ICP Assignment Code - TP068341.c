#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

struct tutor {//tipe data nya tutor, ditampung di myTutor yang dibuat di dalam main
    char tutorID[4]; //[T][0][1][\0]
    char tutorName[50];
    char tutorTitle[50];
    char tutorPassword[10];
};

struct student {
    char studentName[50];
    char studentTP[15];
    char studentPassword[10];
};
struct admin {
    char adminName[35];
    char adminPassword[10];
};

struct session {
    char sessionCode[20];
    char sessionTitle[50];
    char sessionDay[20];
    char sessionStartTime[10];
    char sessionLocation[10];
    char sessionTutorCode[4];
};

struct enroll {
    char sessionCode[7];
    char studentTP[10];
};

//--------------------------------------------------------------------------------------------------------------------------

void createDataManualAdmin(struct admin myAdmin[], int* nAdmin);
void tulisDataAdmin(struct admin myAdmin[], int nAdmin);
void bacaDataAdmin(struct admin myAdmin[], int* nAdmin);
void prepareAdmin(struct admin myAdmin[], int* nAdmin);

//--------------------------------------------------------------------------------------------------------------------------

void createDataManualTutor(struct tutor myTutor[], int* nTutor);
void tulisDataTutor(struct tutor myTutor[], int nTutor);
void bacaDataTutor(struct tutor myTutor[], int* nTutor);
void prepareTutor(struct tutor myTutor[], int* nTutor);

//--------------------------------------------------------------------------------------------------------------------------

void createDataManualStudent(struct student myStudent[], int* nStudent);
void tulisDataStudent(struct student myStudent[], int nStudent);
void bacaDataStudent(struct student myStudent[], int* nStudent);
void prepareStudent(struct student myStudent[], int* nStudent);

//--------------------------------------------------------------------------------------------------------------------------

void createDataManualSession(struct session mySession[], int* nSession);
void tulisDataSession(struct session mySession[], int nSession);
void bacaDataSession(struct session mySession[], int* nSession);
void prepareSession(struct session mySession[], int* nSession);

//--------------------------------------------------------------------------------------------------------------------------

void createDataManualEnroll(struct enroll myEnroll[], int* nEnroll);
void tulisDataEnroll(struct enroll myEnroll[], int nEnroll);
void bacaDataEnroll(struct enroll myEnroll[], int* nEnroll);
void prepareEnroll(struct enroll myEnroll[], int* nEnroll);

//--------------------------------------------------------------------------------------------------------------------------

void roleMenu();

//--------------------------------------------------------------------------------------------------------------------------

void cetakDataTutor(struct tutor myTutor[], int nTutor);
void cetakDataStudent(struct student myStudent[], int nStudent);
void cetakDataSession(struct session mySession[], int nSession);
void cetakDataEnroll(struct enroll myEnroll[], int nEnroll);
void doTutorRegistration(struct tutor myTutor[], int* nTutor);
void doStudentRegistration(struct student myStudent[], int* nStudent);
void doCafeSessionRegistration(struct session mySession[], int *nSession);
void doEnrollRegistration(struct enroll myEnroll[], int *nEnroll);
void menuAdmin();
void doAsAdmin(struct tutor myTutor[], int *nTutor,
               struct student myStudent[], int *nStudent,
               struct session mySession[], int *nSession,
               struct enroll myEnroll[], int *nEnroll);
int loginAdmin(struct admin myAdmin[], int nAdmin);

//--------------------------------------------------------------------------------------------------------------------------

void showTutorSession(struct tutor myTutor[], int nTutor,
                 struct session mySession[], int nSession , int idxTutor);
void menuTutor();
void doAsTutor(struct tutor myTutor[], int nTutor,
               struct session mySession[], int nSession, int idxTutor);
int loginTutor(struct tutor myTutor[], int nTutor, int *idxTutor);

//--------------------------------------------------------------------------------------------------------------------------
void showStudentSession(struct student myStudent[],int nStudent,
                        struct enroll myEnroll[],int nEnroll,
                        struct session mySession[], int nSession,
                        struct tutor myTutor[],int nTutor,
                        int idxStudent);
void menuStudent();
void doAsStudent(struct student myStudent[], int nStudent,
                   struct enroll myEnroll[], int *nEnroll,
                   struct session mySession[], int nSession,
                   struct tutor myTutor[],int nTutor,
                   int idxStudent);
int loginStudent(struct student myStudent[], int nStudent, int *idxStudent);

//---------------------------------------------------------------------------------------------------------------------------

void createDataManualAdmin(struct admin myAdmin[], int* nAdmin)
{
    strcpy(myAdmin[0].adminName, "adm1");
    strcpy(myAdmin[0].adminPassword, "adm1");

    strcpy(myAdmin[1].adminName, "adm2");
    strcpy(myAdmin[1].adminPassword, "adm2");

    strcpy(myAdmin[2].adminName, "adm3");
    strcpy(myAdmin[2].adminPassword, "adm3");

    *nAdmin = 3;
}

//write admin data into files
void tulisDataAdmin(struct admin myAdmin[], int nAdmin)
{
    FILE* fwadmin;
    fwadmin = fopen("admin.dat", "w");
    if (fwadmin != NULL)
    {
        for (int i = 0; i < nAdmin; i++)
        {
            fprintf(fwadmin, "%s,%s\n", myAdmin[i].adminName, myAdmin[i].adminPassword);
        }
        fclose(fwadmin);
    }
    else
    {
        printf("Failed to write file\n");
    }
}

struct admin tokening3(char str[50]) {
    struct admin tempAdmin;
    int position = 1;

    const char s[2] = ",";
    char* token;

    /* get the first token */
    token = strtok(str, s);
    strcpy(tempAdmin.adminName, token);
    // setelah dapet first token, dimasukin ke tempAdmin, bagian name. tempAdmin tipe datanya adalah admin, jadi udah tau isinya apa aja
    //ada adminName, adminPassword
    /* walk through other tokens */
    while (token != NULL) {
        //printf(" %s\n", token);
        token = strtok(NULL, s);
        if (position == 1) {
            token[strlen(token)-1] = '\0';
            strcpy(tempAdmin.adminPassword, token);
            break;
        }
    }
    return tempAdmin;
}

void bacaDataAdmin(struct admin myAdmin[], int* nAdmin)
{
    FILE* fileptr;
    char readstr[100];
    *nAdmin = 0;
    struct admin procAdmin;

    fileptr = fopen("admin.dat", "r");
    while (fgets(readstr, 100, fileptr) != NULL)//membaca perbaris dari file readstr, maks per baris 80, fileptr= membaca dari file dlm fileptr
    {
        procAdmin = tokening3(readstr);//tempAdmin diterima sama procAdmin, readstr masuk ke char str[50]
        strcpy(myAdmin[(*nAdmin)].adminName, procAdmin.adminName);
        strcpy(myAdmin[(*nAdmin)].adminPassword, procAdmin.adminPassword);

        (*nAdmin)++;
    }
}

void prepareAdmin(struct admin myAdmin[], int* nAdmin)
{
    FILE* fradmin;
    fradmin = fopen("admin.dat", "r");
    if (fradmin == NULL)
    {
        createDataManualAdmin(myAdmin, nAdmin);
        tulisDataAdmin(myAdmin, *nAdmin);
    }
    else
    {
        bacaDataAdmin(myAdmin, nAdmin);
    }
}

//--------------------------------------------------------------------------------------------------------------------------

void createDataManualTutor(struct tutor myTutor[], int* nTutor)
{
    strcpy(myTutor[0].tutorID, "T01"); //strcpy masukkan data string atau array of char
    strcpy(myTutor[0].tutorName, "Albert");
    strcpy(myTutor[0].tutorTitle, "Web Development");
    strcpy(myTutor[0].tutorPassword, "abc");

    strcpy(myTutor[1].tutorID, "T02"); //strcpy masukkan data string atau array of char
    strcpy(myTutor[1].tutorName, "Amad");
    strcpy(myTutor[1].tutorTitle, "C Sharp Programming");
    strcpy(myTutor[1].tutorPassword, "def");

    strcpy(myTutor[2].tutorID, "T03"); //strcpy masukkan data string atau array of char
    strcpy(myTutor[2].tutorName, "Steve");
    strcpy(myTutor[2].tutorTitle, "Python Programming");
    strcpy(myTutor[2].tutorPassword, "ghi");

    *nTutor = 3;
}

struct tutor tokening(char str[100]) {
    struct tutor tempTutor;
    int position = 1;

    const char s[2] = ",";
    char* token;

    /* get the first token */
    token = strtok(str, s);
    strcpy(tempTutor.tutorID, token);

    /* walk through other tokens */
    while (token != NULL) {
        //printf(" %s\n", token);
        token = strtok(NULL, s);
        if (position == 1) {
            strcpy(tempTutor.tutorName, token);
            position++;
        }
        else if (position == 2) {
            strcpy(tempTutor.tutorTitle, token);
            position++;
        }
        else if (position == 3)
        {
            token[strlen(token)-1] = '\0'; //untuk menghapus tanda \n di akhir baris
            strcpy(tempTutor.tutorPassword, token);
            break;
        }
    }
    return tempTutor;
}

void bacaDataTutor(struct tutor myTutor[], int* nTutor)
{
    FILE* fileptr;//fileptr akan membaca dari tutor.dat
    char readstr[100]; //penampung bacaan sebaris
    *nTutor = 0; //dibaca dari 0 lho
    struct tutor procTutor;

    fileptr = fopen("tutor.dat", "r");
    while (fgets(readstr, 100, fileptr) != NULL) { //baca perbaris T01,Albert,Web Development
        procTutor = tokening(readstr); //hasil sebaris ditokening
        strcpy(myTutor[(*nTutor)].tutorID, procTutor.tutorID);
        strcpy(myTutor[(*nTutor)].tutorName, procTutor.tutorName);
        strcpy(myTutor[(*nTutor)].tutorTitle, procTutor.tutorTitle);
        strcpy(myTutor[(*nTutor)].tutorPassword, procTutor.tutorPassword);
        (*nTutor)++; //record berikutnya
    }
}
void tulisDataTutor(struct tutor myTutor[], int nTutor)
{
    FILE* fwtutor;
    fwtutor = fopen("tutor.dat", "w");
    if (fwtutor != NULL) { //gagal jika km ga ada hak tulis di hdd
        for (int i = 0; i < nTutor; i++) {
            fprintf(fwtutor, "%s,%s,%s,%s\n", myTutor[i].tutorID, myTutor[i].tutorName, myTutor[i].tutorTitle, myTutor[i].tutorPassword);
        }
        fclose(fwtutor);
    }
    else {
        printf("Failed to write file\n");
    }
}

void prepareTutor(struct tutor myTutor[], int* nTutor)
{
    FILE* frtutor;
    frtutor = fopen("tutor.dat", "r"); //sefolder dengan source code r = read
    //if the file is not available - for the first time, write the hardcoded data

    if (frtutor == NULL) { //tidak ketemu file nya
        createDataManualTutor(myTutor, nTutor);
        tulisDataTutor(myTutor, *nTutor); //pass by value saja karena ga ada perubahan
    }
    else { //jika ketemu maka tinggal baca saja
        bacaDataTutor(myTutor, nTutor);
    }
}

//--------------------------------------------------------------------------------------------------------------------------

void createDataManualStudent(struct student myStudent[], int* nStudent)
{
    strcpy(myStudent[0].studentName, "Eliza");
    strcpy(myStudent[0].studentTP, "TP068341");
    strcpy(myStudent[0].studentPassword, "12345");

    strcpy(myStudent[1].studentName, "Clarissa");
    strcpy(myStudent[1].studentTP, "TP008090");
    strcpy(myStudent[1].studentPassword, "67891");

    strcpy(myStudent[2].studentName, "Eliana");
    strcpy(myStudent[2].studentTP, "TP100505");
    strcpy(myStudent[2].studentPassword, "01112");

    strcpy(myStudent[3].studentName, "Kayla");
    strcpy(myStudent[3].studentTP, "TP067060");
    strcpy(myStudent[3].studentPassword, "13141");

    *nStudent = 4;
}

struct student tokening2(char str2[50]) {
    struct student tempStudent;
    int position = 1;

    const char s[2] = ",";
    char* token2;

    /* get the first token */
    token2 = strtok(str2, s);
    strcpy(tempStudent.studentName, token2);

    /* walk through other tokens */
    while (token2 != NULL) {
        //printf(" %s\n", token);
        token2 = strtok(NULL, s);
        if (position == 1) {
            strcpy(tempStudent.studentTP, token2);
            position++;
        }
        else if (position == 2) {
            token2[strlen(token2)-1] = '\0';
            strcpy(tempStudent.studentPassword, token2);
            break;
        }
    }
    return tempStudent;
}


void bacaDataStudent(struct student myStudent[], int* nStudent)
{
    FILE* fileptr2;
    char readstr2[100];
    *nStudent = 0;
    struct student procStudent;

    fileptr2 = fopen("student.dat", "r");
    while (fgets(readstr2, 100, fileptr2) != NULL)
    {
        procStudent = tokening2(readstr2);
        strcpy(myStudent[(*nStudent)].studentName, procStudent.studentName);
        strcpy(myStudent[(*nStudent)].studentTP, procStudent.studentTP);
        strcpy(myStudent[(*nStudent)].studentPassword, procStudent.studentPassword);
        (*nStudent)++;
    }
}


void tulisDataStudent(struct student myStudent[], int nStudent)
{
    FILE* fwstudent;
    fwstudent = fopen("student.dat", "w");
    if (fwstudent != NULL)
    {
        for (int i = 0; i < nStudent; i++)
        {
            fprintf(fwstudent, "%s,%s,%s\n", myStudent[i].studentName, myStudent[i].studentTP, myStudent[i].studentPassword);
        }
        fclose(fwstudent);
    }
    else
    {
        printf("Failed to write file\n");
    }
}

void prepareStudent(struct student myStudent[], int* nStudent)
{
    FILE* frstudent;
    frstudent = fopen("student.dat", "r");
    if (frstudent == NULL)
    {
        createDataManualStudent(myStudent, nStudent);
        tulisDataStudent(myStudent, *nStudent);
    }
    else
    {
        bacaDataStudent(myStudent, nStudent);
    }
}

//--------------------------------------------------------------------------------------------------------------------------

void createDataManualSession(struct session mySession[], int* nSession)
{

    strcpy(mySession[0].sessionCode, "PYP101");
    strcpy(mySession[0].sessionTitle, "Python Programming");
    strcpy(mySession[0].sessionDay, "Saturday");
    strcpy(mySession[0].sessionStartTime, "9.00am");
    strcpy(mySession[0].sessionLocation, "C-01-01");
    strcpy(mySession[0].sessionTutorCode, "T01");

    strcpy(mySession[1].sessionCode, "JAV102");
    strcpy(mySession[1].sessionTitle, "Java Programming");
    strcpy(mySession[1].sessionDay, "Sunday");
    strcpy(mySession[1].sessionStartTime, "9.00am");
    strcpy(mySession[1].sessionLocation, "C-01-02");
    strcpy(mySession[1].sessionTutorCode, "T02");

    strcpy(mySession[2].sessionCode, "CPL103");
    strcpy(mySession[2].sessionTitle, "C Programming");
    strcpy(mySession[2].sessionDay, "Saturday");
    strcpy(mySession[2].sessionStartTime, "2.00pm");
    strcpy(mySession[2].sessionLocation, "C-01-03");
    strcpy(mySession[2].sessionTutorCode, "T03");

    strcpy(mySession[3].sessionCode, "WEB104");
    strcpy(mySession[3].sessionTitle, "Web Development");
    strcpy(mySession[3].sessionDay, "Sunday");
    strcpy(mySession[3].sessionStartTime, "2.00pm");
    strcpy(mySession[3].sessionLocation, "C-01-04");
    strcpy(mySession[3].sessionTutorCode, "T04");

    strcpy(mySession[4].sessionCode, "CSP105");
    strcpy(mySession[4].sessionTitle, "C Sharp Programming");
    strcpy(mySession[4].sessionDay, "Monday");
    strcpy(mySession[4].sessionStartTime, "7.00pm");
    strcpy(mySession[4].sessionLocation, "C-01-05");
    strcpy(mySession[4].sessionTutorCode, "T05");

    *nSession = 5;
}

void tulisDataSession(struct session mySession[], int nSession)
{
    FILE* fwsession;
    fwsession = fopen("session.dat", "w");
    if (fwsession != NULL)
    {
        for (int i = 0; i < nSession; i++)
        {
            fprintf(fwsession, "%s,%s,%s,%s,%s,%s\n",
                    mySession[i].sessionCode,
                    mySession[i].sessionTitle,
                    mySession[i].sessionDay,
                    mySession[i].sessionStartTime,
                    mySession[i].sessionLocation,
                    mySession[i].sessionTutorCode
                    );
        }
        fclose(fwsession);
    }
    else
    {
        printf("Failed to write file\n");
    }
}

struct session tokening4(char str[100]) {
    struct session tempSession;
    int position = 1;

    const char s[2] = ",";
    char* token;
    /* get the first token */
    token = strtok(str, s);
    strcpy(tempSession.sessionCode, token);
    /* walk through other tokens */
    while (token != NULL) {
        //printf(" %s\n", token);
        token = strtok(NULL, s);
        if (position == 1) {
            strcpy(tempSession.sessionTitle, token);
            position++;
        }
        else if (position == 2) {
            strcpy(tempSession.sessionDay, token);
            position++;
        }
        else if (position == 3) {
            strcpy(tempSession.sessionStartTime, token);
            position++;
        }
        else if (position == 4) {
            strcpy(tempSession.sessionLocation, token);
            position++;
        }
        else if (position == 5) {
            token[strlen(token)-1] = '\0';
            strcpy(tempSession.sessionTutorCode, token);
            break;
        }
    }
    return tempSession;
}

void bacaDataSession(struct session mySession[], int* nSession)
{
    FILE* fileptr;
    char readstr[100];
    *nSession = 0;

    struct session procSession;
    fileptr = fopen("session.dat", "r");
    while (fgets(readstr, 100, fileptr) != NULL)
    {
        procSession = tokening4(readstr);
        strcpy(mySession[(*nSession)].sessionCode, procSession.sessionCode);
        strcpy(mySession[(*nSession)].sessionTitle, procSession.sessionTitle);
        strcpy(mySession[(*nSession)].sessionDay, procSession.sessionDay);
        strcpy(mySession[(*nSession)].sessionStartTime, procSession.sessionStartTime);
        strcpy(mySession[(*nSession)].sessionLocation, procSession.sessionLocation);
        strcpy(mySession[(*nSession)].sessionTutorCode, procSession.sessionTutorCode);

        (*nSession)++;
    }
}

void prepareSession(struct session mySession[], int* nSession)
{
    FILE* frsession;
    frsession = fopen("session.dat", "r");
    *nSession = 0;
    if (frsession == NULL)
    {
        createDataManualSession(mySession, nSession);
        tulisDataSession(mySession, *nSession);
    }
    else
    {
        bacaDataSession(mySession, nSession);
    }
}

//--------------------------------------------------------------------------------------------------------------------------

void createDataManualEnroll(struct enroll myEnroll[], int* nEnroll)
{
    strcpy(myEnroll[0].sessionCode, "PYP101");
    strcpy(myEnroll[0].studentTP, "TP068341");

    strcpy(myEnroll[1].sessionCode, "JAV102");
    strcpy(myEnroll[1].studentTP, "TP068341");

    strcpy(myEnroll[2].sessionCode, "CPL103");
    strcpy(myEnroll[2].studentTP, "TP068341");

    strcpy(myEnroll[3].sessionCode, "JAV102");
    strcpy(myEnroll[3].studentTP, "TP008090");

    strcpy(myEnroll[4].sessionCode, "CPL103");
    strcpy(myEnroll[4].studentTP, "TP008090");

    *nEnroll = 5;
}

struct enroll tokening5(char str[100]) {
    struct enroll tempEnroll;
    int position = 1;

    const char s[2] = ",";
    char* token;

    /* get the first token */
    token = strtok(str, s);
    strcpy(tempEnroll.sessionCode, token);

    /* walk through other tokens */
    while (token != NULL) {
        //printf(" %s\n", token);
        token = strtok(NULL, s);
        if (position == 1) {
            token[strlen(token)-1] = '\0';
            strcpy(tempEnroll.studentTP, token);
            break;
        }
    }
    return tempEnroll;
}

void bacaDataEnroll(struct enroll myEnroll[], int* nEnroll)
{
    FILE* fileptr;//fileptr akan membaca dari tutor.dat
    char readstr[100]; //penampung bacaan sebaris
    *nEnroll = 0; //dibaca dari 0
    struct enroll procEnroll;

    fileptr = fopen("enroll.dat", "r");
    while (fgets(readstr, 100, fileptr) != NULL) { //baca perbaris T01,Albert,Web Development
        procEnroll = tokening5(readstr); //hasil sebaris ditokening
        strcpy(myEnroll[(*nEnroll)].sessionCode, procEnroll.sessionCode);
        strcpy(myEnroll[(*nEnroll)].studentTP, procEnroll.studentTP);
        (*nEnroll)++; //record berikutnya
    }
}

void tulisDataEnroll(struct enroll myEnroll[], int nEnroll)
{
    FILE* fwenroll;
    fwenroll = fopen("enroll.dat", "w");
    if (fwenroll != NULL) { //gagal jika km ga ada hak tulis di hdd
        for (int i = 0; i < nEnroll; i++) {
            fprintf(fwenroll, "%s,%s\n", myEnroll[i].sessionCode, myEnroll[i].studentTP);
        }
        fclose(fwenroll);
    }
    else {
        printf("Gagal menulis file\n");
    }
}

void prepareEnroll(struct enroll myEnroll[], int* nEnroll)
{
    FILE* frenroll;
    frenroll = fopen("enroll.dat", "r"); //sefolder dengan source code r = read
    //if the file is not available - for the first time, write the hardcoded data

    if (frenroll == NULL) { //tidak ketemu file nya
        createDataManualEnroll(myEnroll, nEnroll);
        tulisDataEnroll(myEnroll, *nEnroll); //pass by value saja karena ga ada perubahan
    }
    else { //jika ketemu maka tinggal baca saja
        bacaDataEnroll(myEnroll, nEnroll);
    }
}

//--------------------------------------------------------------------------------------------------------------------------

void roleMenu()
{
    printf(" WELCOME TO PROGRAMMING CAFE\n");
    printf("---------------------------\n");
    printf("        LOGIN AS\n\n");
    printf("    1. Admin\n");
    printf("    2. Tutor\n");
    printf("    3. Student\n");
    printf("    4. Exit\n\n");
    printf("        Choose [1-4] : ");
}

//--------------------------------------------------------------------------------------------------------------------------

void cetakDataTutor(struct tutor myTutor[], int nTutor)
{
    printf("LIST OF TUTORS\n");
    printf("-----------------------------------------------------------\n");
    for (int i = 0; i < nTutor; i++)
    {
        printf("%5s%20s%20s%20s\n", myTutor[i].tutorID,
            myTutor[i].tutorName,
            myTutor[i].tutorTitle,
            myTutor[i].tutorPassword);
    }
    printf("\n---------------------------------------------------------\n");
}
void cetakDataStudent(struct student myStudent[], int nStudent)
{
    printf("LIST OF STUDENTS\n");
    printf("-----------------------------------------------------------\n");
    for (int i = 0; i < nStudent; i++)
    {
        printf("%5s%20s%20s\n", myStudent[i].studentTP,
            myStudent[i].studentName,
            myStudent[i].studentPassword);
    }
    printf("\n---------------------------------------------------------\n");
}

void cetakDataSession(struct session mySession[], int nSession)
{
    printf("LIST OF SESSIONS AVAILABLE\n");
    printf("-------------------------------------------------------------------\n");
    for (int i = 0; i < nSession; i++)
    {
        printf("%6s%20s%10s%10s%10s%10s\n", mySession[i].sessionCode,
            mySession[i].sessionTitle,
            mySession[i].sessionDay,
            mySession[i].sessionStartTime,
            mySession[i].sessionLocation,
            mySession[i].sessionTutorCode
            );
    }
    printf("\n------------------------------------------------------------------\n");
}

void cetakDataEnroll(struct enroll myEnroll[], int nEnroll)
{
    printf("LIST OF STUDENTS ENROLLED IN ALL SESSIONS\n");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < nEnroll; i++)
    {
        printf("%6s%20s\n", myEnroll[i].sessionCode,
            myEnroll[i].studentTP
            );
    }
    printf("\n----------------------------------------------------------\n");
}

void doTutorRegistration(struct tutor myTutor[], int* nTutor)
{
    printf("REGISTRATION FOR TUTOR\n\n");
    int valid = -1;
    while(valid == -1){
        printf("    Tutor ID        : ");
        scanf("%s",&myTutor[*nTutor].tutorID);
        int ketemu = 0;
        for(int i=0;i<*nTutor;i++)
        {
            if(strcmp(myTutor[i].tutorID,myTutor[*nTutor].tutorID) == 0)
            {
                ketemu++;
            }
        }
        if (ketemu == 1){
            printf("Tutor ID already exists\nPlease input another ID\n");
        }
        else{
            valid=1;
        }
    }
    printf("    Tutor Name      : ");
    getchar();
    gets(myTutor[*nTutor].tutorName);
    printf("    Title           : ");
    gets(myTutor[*nTutor].tutorTitle);
    printf("    Tutor Pasword   : ");
    gets(myTutor[*nTutor].tutorPassword);
    (*nTutor)++;
}
void doStudentRegistration(struct student myStudent[], int* nStudent)
{
    printf("REGISTRATION FOR Student\n\n");
    int valid2 = -1;
    getchar();
    while(valid2 == -1)
    {
        printf("    Student Name      : ");
        gets(myStudent[*nStudent].studentName);
        printf("    Student TP        : ");
        gets(myStudent[*nStudent].studentTP);
        int found = 0;
        for(int i=0;i<*nStudent;i++)
        {

            if(strcmp(myStudent[i].studentTP,myStudent[*nStudent].studentTP)==0)
            {
                found++;
            }
        }
        if(found == 1)
        {
            printf("Student name and TP Number already exist\n");
        }
        else{
            valid2=1;
        }
    }
    printf("    Student Password  : ");
    gets(myStudent[*nStudent].studentPassword);
    (*nStudent)++;
}



void doCafeSessionRegistration(struct session mySession[], int *nSession)
{
    printf("REGISTRATION FOR Cafe Programming Session\n\n");

    int valid3 = -1;
    getchar();
    while (valid3 == -1)
    {
        printf("    Session Code       : ");
        gets(mySession[*nSession].sessionCode);
        int founded = 0;
        for(int i=0;i<*nSession;i++)
        {
            if(strcmp(mySession[i].sessionCode,mySession[*nSession].sessionCode)== 0)
            {
                founded++;
            }
        }
        if (founded == 1)
        {
            printf("Session Code already exist\nPlease input another code\n");
        }else
        {
            valid3 = 1;
        }

    }


    printf("    Session Title      : ");
    gets(mySession[*nSession].sessionTitle);
    printf("    Session Day        : ");
    gets(mySession[*nSession].sessionDay);
    printf("    Session Start Time : ");
    gets(mySession[*nSession].sessionStartTime);
    printf("    Session Location   : ");
    gets(mySession[*nSession].sessionLocation);
    printf("    Session Tutor Code : ");
    gets(mySession[*nSession].sessionTutorCode);
    (*nSession)++;
}

void doEnrollRegistration(struct enroll myEnroll[], int *nEnroll)
{
    printf("STUDENT ENROLLMENT FOR Cafe Programming Session\n\n");
    getchar();
    printf("    Session Code       : ");
    gets(myEnroll[*nEnroll].sessionCode);
    printf("    Student TP         : ");
    gets(myEnroll[*nEnroll].studentTP);
    printf("Enrollment has been saved\n");
    (*nEnroll)++;
}


void menuAdmin()
{
    printf("  1. Registration of Tutor\n");
    printf("  2. Show tutor list\n");
    printf("  3. Registration of Student\n");
    printf("  4. Show student list\n");
    printf("  5. Add new Programming Cafe session\n");
    printf("  6. Show session list\n");
    printf("  7. Enroll student in Programming Cafe session\n");
    printf("  8. Show sessions and enrolled student details\n");
    printf("  9. Exit\n");
}

void doAsAdmin(struct tutor myTutor[], int *nTutor,
               struct student myStudent[], int *nStudent,
               struct session mySession[], int *nSession,
               struct enroll myEnroll[], int *nEnroll)
{
    int cAdmin = 0;
    while (cAdmin != 9)
    {
        menuAdmin();
        printf("Choose number: \n");
        scanf("%d", &cAdmin);
        if (cAdmin == 1) {
            doTutorRegistration(myTutor, nTutor);
            tulisDataTutor(myTutor, *nTutor);
        }
        else if (cAdmin == 2) {
            cetakDataTutor(myTutor, *nTutor);
        }
        else if (cAdmin == 3) {
            doStudentRegistration(myStudent, nStudent);
            tulisDataStudent(myStudent, *nStudent);
        }
        else if (cAdmin == 4) {
            cetakDataStudent(myStudent, *nStudent);
        }
        else if (cAdmin == 5) {
            doCafeSessionRegistration(mySession, nSession);
            tulisDataSession(mySession, *nSession);
        }
        else if (cAdmin == 6) {
            cetakDataSession(mySession, *nSession);
        }
        else if (cAdmin == 7) {
            doEnrollRegistration(myEnroll, nEnroll);
            tulisDataEnroll(myEnroll, *nEnroll);
        }
        else if (cAdmin == 8) {
            cetakDataEnroll(myEnroll, *nEnroll);
        }
    }
}

int loginAdmin(struct admin myAdmin[], int nAdmin)
{
    char username[50];
    char password[50];
    printf("=> Username : ");
    scanf("%s",&username);
    printf("=> Password : ");
    scanf("%s",&password);
    int ada = 0;
    for (int i=0; i<nAdmin; i++){
        if (strcmp(myAdmin[i].adminName,username)==0 &&
            strcmp(myAdmin[i].adminPassword,password)==0){
                ada++;
            }
    }
    return ada;
}

//--------------------------------------------------------------------------------------------------------------------------


void showTutorSession(struct tutor myTutor[], int nTutor,
                 struct session mySession[], int nSession , int idxTutor)
{
    printf("Here is your session list\n");
    for (int i=0; i<nSession; i++)
    {
        if (strcmp(mySession[i].sessionTutorCode, myTutor[idxTutor].tutorID)==0)
        {
            printf("%6s %30s %30s\n", mySession[i].sessionCode, mySession[i].sessionDay, mySession[i].sessionLocation);
        }
    }
    printf("\n");
}

void menuTutor()
{
    printf("1. Tutor Session\n");
    printf("2. Exit\n");
}


void doAsTutor(struct tutor myTutor[], int nTutor,
               struct session mySession[], int nSession, int idxTutor)
{
    int cTutor=-1;
    while (cTutor != 2)
    {
        menuTutor();
        scanf("%d", &cTutor);
        if (cTutor == 1) {
            showTutorSession(myTutor, nTutor, mySession, nSession, idxTutor);
        }
    }
}


int loginTutor(struct tutor myTutor[], int nTutor, int *idxTutor)
{
    char username[50];
    char password[50];
    printf("=> Tutor ID : ");
    scanf("%s",&username);
    printf("=> Password : ");
    scanf("%s",&password);
    int ada = 0;
    for (int i=0; i<nTutor; i++){
        if (strcmp(myTutor[i].tutorID,username)==0 &&
            strcmp(myTutor[i].tutorPassword,password)==0){
                ada++;
                *idxTutor = i;
            }
    }
    return ada;
}

//--------------------------------------------------------------------------------------------------------------------------


void studentRegisterSession(struct student myStudent[], int nStudent,
                   struct enroll myEnroll[], int *nEnroll,
                   struct session mySession[], int nSession,
                   int idxStudent)
{
    //session totalnya apa saja
    int answer=0;
    cetakDataSession(mySession, nSession);
    printf("Here is the list of available sessions..");
    printf("Do you want to register in any session ? \n [1=yes 0=no] => ");
    scanf("%d",&answer);
    if (answer==1){
        printf("STUDENT ENROLLMENT FOR Cafe Programming Session\n\n");
        getchar();
        printf("    Session Code       : ");
        gets(myEnroll[*nEnroll].sessionCode);
        strcpy(myEnroll[*nEnroll].studentTP, myStudent[idxStudent].studentTP);
        (*nEnroll)++;
        tulisDataEnroll(myEnroll, *nEnroll);
        printf("You have been enrolled to the chosen session\n Please check your session list again\n");
    }
}
void showStudentSession(struct student myStudent[],int nStudent,
                        struct enroll myEnroll[],int nEnroll,
                        struct session mySession[], int nSession,
                        struct tutor myTutor[],int nTutor,
                        int idxStudent)
{
    printf("Here is your session list:\n");
    for(int i=0;i<nEnroll;i++)
    {
        if(strcmp(myEnroll[i].studentTP,myStudent[idxStudent].studentTP)==0)
        {
            for(int j=0;j<nSession;j++)
            {
                if(strcmp(mySession[j].sessionCode,myEnroll[i].sessionCode)==0){
                    for(int k=0;k<nTutor;k++)
                    {
                        if(strcmp(myTutor[k].tutorID,mySession[j].sessionTutorCode)==0)
                        {
                            printf("%6s %30s %30s %30s %30s %30s %30s\n",myEnroll[i].sessionCode,
                             mySession[j].sessionTitle,mySession[j].sessionDay,
                             mySession[j].sessionStartTime, mySession[j].sessionLocation,
                             mySession[j].sessionTutorCode,myTutor[k].tutorName);
                        }
                    }
                }
            }
        }
    }
};
void menuStudent()
{
    printf("1. Student Session\n");
    printf("2. Registration Session\n");
    printf("3. Exit\n");
}

void doAsStudent(struct student myStudent[], int nStudent,
                   struct enroll myEnroll[], int *nEnroll,
                   struct session mySession[], int nSession,
                   struct tutor myTutor[],int nTutor,
                   int idxStudent)
{
    int cStudent=-1;
    while (cStudent != 3)
    {

        menuStudent();
        scanf("%d",&cStudent);
        if(cStudent == 1)
        {
            showStudentSession(myStudent, nStudent, myEnroll, *nEnroll,mySession, nSession,myTutor,nTutor, idxStudent);
        }else if (cStudent == 2)
        {
            studentRegisterSession(myStudent, nStudent, myEnroll, nEnroll,mySession, nSession,idxStudent);
        }
    }
}

int loginStudent(struct student myStudent[], int nStudent, int *idxStudent)
{
    char username[50];
    char password[50];
    printf("=> Student TP : ");
    scanf("%s",&username);
    printf("=> Password   : ");
    scanf("%s",&password);
    int ada = 0;
    for (int i=0; i<nStudent; i++){
        if (strcmp(myStudent[i].studentTP,username)==0 &&
            strcmp(myStudent[i].studentPassword,password)==0){
                ada++;
                *idxStudent = i;
            }
    }
    return ada;
}

//--------------------------------------------------------------------------------------------------------------------------

int main()
{
    struct admin myAdmin[100];
    struct tutor myTutor[100];
    struct student myStudent[100];
    struct session mySession[100];
    struct enroll myEnroll[100];

    int nAdmin = 0;
    int nTutor = 0;
    int nStudent = 0;
    int nSession = 0;
    int nEnroll = 0;

    prepareAdmin(myAdmin, &nAdmin);
    prepareTutor(myTutor, &nTutor);
    prepareStudent(myStudent, &nStudent);
    prepareSession(mySession, &nSession);
    prepareEnroll(myEnroll, &nEnroll);

    int cRole = 0;
    while (cRole != 4)
    {
        roleMenu();
        scanf("%d", &cRole);
        if (cRole == 1) {
            if (loginAdmin(myAdmin,nAdmin)==1){
                doAsAdmin(myTutor, &nTutor,
                      myStudent, &nStudent,
                      mySession, &nSession,
                      myEnroll, &nEnroll
                      );//kalau mau nambah tutor, jumlahnya akan ikut bertambah, ajdi pakai &
                //ada struct tutor untuk nambah data dari ketikan
            }else{
                printf("Maaf Invalid username/password\n");
            }
        }
        else if (cRole == 2) {
            int idxTutor = -1;
            if (loginTutor(myTutor,nTutor,&idxTutor)==1){
                doAsTutor(myTutor,nTutor, mySession,nSession, idxTutor);
            }else{
                printf("Maaf Invalid username/password\n");
            }
        }
        else if (cRole == 3) {
            int idxStudent = -1;
            if (loginStudent(myStudent,nStudent,&idxStudent)==1){
                doAsStudent(myStudent, nStudent, myEnroll, &nEnroll, mySession, nSession,myTutor, nTutor, idxStudent);
            }else{
                printf("Maaf Invalid username/password\n");
            }
        }
        else if (cRole != 4) {
            printf("Invalid Choosen\n");
        }
    }

}


