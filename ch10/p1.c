struct Phone_Number{
   char quhao[4];//区号
   char jiaohuantai[5];//交换台
   char zhantaihao[5];//站台号
};

struct Date{
  int year;
  int month;
  int day;
};

struct Time{
  int hour;
  int minute;
  int second;
};

struct Message{
  struct Phone_Number phone_number[3];
  struct Date *date;
  struct Time *time;
};
