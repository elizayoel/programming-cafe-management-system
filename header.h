void createDataManualAdmin(struct admin myAdmin[], int* nAdmin);
void tulisDataAdmin(struct admin myAdmin[], int nAdmin);
void bacaDataAdmin(struct admin myAdmin[], int* nAdmin);
void prepareAdmin(struct admin myAdmin[], int* nAdmin);


void createDataManualTutor(struct tutor myTutor[], int* nTutor);
void tulisDataTutor(struct tutor myTutor[], int nTutor);
void bacaDataTutor(struct tutor myTutor[], int* nTutor);
void prepareTutor(struct tutor myTutor[], int* nTutor);


void createDataManualStudent(struct student myStudent[], int* nStudent);
void tulisDataStudent(struct student myStudent[], int nStudent);
void bacaDataStudent(struct student myStudent[], int* nStudent);
void prepareStudent(struct student myStudent[], int* nStudent);

void createDataManualSession(struct session mySession[], int* nSession);
void tulisDataSession(struct session mySession[], int nSession);
void bacaDataSession(struct session mySession[], int* nSession);
void prepareSession(struct session mySession[], int* nSession);


void createDataManualEnroll(struct enroll myEnroll[], int* nEnroll);
void tulisDataEnroll(struct enroll myEnroll[], int nEnroll);
void bacaDataEnroll(struct enroll myEnroll[], int* nEnroll);
void prepareEnroll(struct enroll myEnroll[], int* nEnroll);


void roleMenu();



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


void showTutorSession(struct tutor myTutor[], int nTutor,
                 struct session mySession[], int nSession , int idxTutor);
void menuTutor();
void doAsTutor(struct tutor myTutor[], int nTutor,
               struct session mySession[], int nSession, int idxTutor);
int loginTutor(struct tutor myTutor[], int nTutor, int *idxTutor);


void studentRegisterSession(struct student myStudent[], int nStudent,
                   struct enroll myEnroll[], int *nEnroll,
                   struct session mySession[], int nSession,
                   int idxStudent);
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