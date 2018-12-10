// C program to demonstrate use of variable
// number of arguments.
#include <stdarg.h>
#include <stdio.h>
//#include <sqlite3ext.h>

typedef struct DateTime DateTime;
struct DateTime {

  //sqlite3_int64 iJD; /* The julian day number times 86400000 */
  //long long double iJD;

  double iJD;
  int Y, M, D;       /* Year, month, and day */
  int h, m;          /* Hour and minutes */
  int tz;            /* Timezone offset in minutes */
  double s;          /* Seconds */
  int validYMD;     /* True (1) if Y,M,D are valid */
  int validHMS;     /* True (1) if h,m,s are valid */
  int validJD;      /* True (1) if iJD is valid */
  int validTZ;      /* True (1) if tz is valid */

};

//typedef DateTime;

int sqlite3Isdigit(char ch){

     if(ch>='0' && ch<='9')return 1;
     return 0;
}

static int getDigits(const char *zDate, ...){

  va_list ap;

  int val;
  int N;
  int min;
  int max;
  int nextC;
  int *pVal;
  int cnt = 0;
  va_start(ap, zDate);

  do{

    N = va_arg(ap, int);
    min = va_arg(ap, int);
    max = va_arg(ap, int);
    nextC = va_arg(ap, int);
    pVal = va_arg(ap, int*);
    val = 0;

    while( N-- ){

      /*if( !sqlite3Isdigit(*zDate) ){
        goto end_getDigits;
      }*/

      if( *zDate<'0' && *zDate>'9' ){
        goto end_getDigits;
      }

      val = val*10 + *zDate - '0';
      zDate++;

    }

    printf(" N   %d\n min  %d\n  max  %d\n nextC  %c\n val %d\n",N,min,max,nextC,val);

    if( val<min || val>max || (nextC!=0 && nextC!=*zDate) ){
      goto end_getDigits;
    }

    *pVal = val;
    zDate++;
    cnt++;

  }while( nextC );

end_getDigits:
  va_end(ap);
  printf("cnt  %d\n",cnt);
  return cnt;

}


static int parseTimezone(const char *zDate, DateTime *p){
  int sgn = 0;
  int nHr, nMn;
  int c;
  //while( sqlite3Isspace(*zDate) ){ zDate++; }

  printf("parseTimeZone hour %d\n minutes %d\n s.mili  %lf\n",p->h,p->m,p->s);

  while(*zDate==' '){ zDate++; }
  p->tz = 0;
  c = *zDate;
  if( c=='-' ){
    sgn = -1;
  }else if( c=='+' ){
    sgn = +1;
  }else if( c=='Z' || c=='z' ){
    zDate++;
    goto zulu_time;
  }else{
    return c!=0;
  }
  zDate++;
  if( getDigits(zDate, 2, 0, 14, ':', &nHr, 2, 0, 59, 0, &nMn)!=2 ){
    return 1;
  }
  zDate += 5;
  p->tz = sgn*(nMn + nHr*60);
  printf("tz  %d \n",p->tz);

zulu_time:
  //while( sqlite3Isspace(*zDate) ){ zDate++; }
  while(*zDate==' '){ zDate++; }
  return *zDate!=0;

}



static int parseHhMmSs(const char *zDate, DateTime *p){

  int h, m,s;
  double ms = 0.0;

  if( getDigits(zDate, 2, 0, 24, ':', &h, 2, 0, 59, 0, &m)!=2 ){
    return 1;
  }

  zDate += 5;

  if( *zDate==':' ){

    zDate++;
    printf("\n\n\nheeeeelllllllllllllllooooooooooooo\n");
    if( getDigits(zDate, 2, 0, 59, 0, &s)!=1 ){
      return 1;
    }

    zDate += 2;
    if( *zDate=='.' && sqlite3Isdigit(zDate[1]) ){

      double rScale = 1.0;
      zDate++;
      while( sqlite3Isdigit(*zDate) ){

        ms = ms*10.0 + *zDate - '0';
        rScale *= 10.0;
        zDate++;

      }
      ms /= rScale;
      printf("%lf mili second  \n",ms);
    }

  }else{
    s = 0;
  }
  printf(" hour %d\n minutes %d\n s.mili  %d\n",h,m,s);
  double temp=0.0;
  temp=(double)s;
  printf("%lf\n",temp);

  p->validJD = 0;
  p->validHMS = 1;
  p->h = h;
  p->m = m;
  p->s = (double)s + ms;
  printf(" hour %d\n minutes %d\n s.mili  %lf\n",p->h,p->m,p->s);
  if( parseTimezone(zDate, p) ) return 1;
  printf(" hour %d\n minutes %d\n s.mili  %lf\n tz  %d\n",p->h,p->m,p->s,p->tz);
  p->validTZ = (p->tz!=0)?1:0;

  return 0;

}

static void computeJD(DateTime *p){
  int Y, M, D, A, B, X1, X2;

  if( p->validJD ) return;
  if( p->validYMD ){
    Y = p->Y;
    M = p->M;
    D = p->D;
  }else{
    Y = 2000;  /* If no YMD specified, assume 2000-Jan-01 */
    M = 1;
    D = 1;
  }
  if( M<=2 ){
    Y--;
    M += 12;
  }
  A = Y/100;
  B = 2 - A + (A/4);
  X1 = 36525*(Y+4716)/100;
  X2 = 306001*(M+1)/10000;
  p->iJD = (double)((X1 + X2 + D + B - 1524.5 ) * 86400000);
  p->validJD = 1;
  if( p->validHMS ){
    p->iJD += p->h*3600000 + p->m*60000 + (double)(p->s*1000);
    if( p->validTZ ){
      p->iJD -= p->tz*60000;
      p->validYMD = 0;
      p->validHMS = 0;
      p->validTZ = 0;
    }
  }
}




static int parseYyyyMmDd(const char *zDate, DateTime *p){
  int Y, M, D, neg;

  if( zDate[0]=='-' ){
    zDate++;
    neg = 1;
  }else{
    neg = 0;
  }
  if( getDigits(zDate,4,0,9999,'-',&Y,2,1,12,'-',&M,2,1,31,0,&D)!=3 ){
    return 1;
  }
  zDate += 10;
  while( *zDate==' ' ){ zDate++; }
  if( parseHhMmSs(zDate, p)==0 ){
    /* We got the time */
  }else if( *zDate==0 ){
    p->validHMS = 0;
  }else{
    return 1;
  }
  p->validJD = 0;
  p->validYMD = 1;
  p->Y = neg ? -Y : Y;
  p->M = M;
  p->D = D;
  if( p->validTZ ){
    computeJD(p);
  }
  return 0;
}











static void computeYMD(DateTime *p){
  int Z, A, B, C, D, E, X1;
  if( p->validYMD ) return;
  if( !p->validJD ){
    p->Y = 2000;
    p->M = 1;
    p->D = 1;
  }else{
    Z = (int)((p->iJD + 43200000)/86400000);
    A = (int)((Z - 1867216.25)/36524.25);
    A = Z + 1 + A - (A/4);
    B = A + 1524;
    C = (int)((B - 122.1)/365.25);
    D = (36525*C)/100;
    E = (int)((B-D)/30.6001);
    X1 = (int)(30.6001*E);
    p->D = B - D - X1;
    p->M = E<14 ? E-1 : E-13;
    p->Y = p->M>2 ? C - 4716 : C - 4715;
  }
  p->validYMD = 1;
}


/*
** Compute the Hour, Minute, and Seconds from the julian day number.
*/


static void computeHMS(DateTime *p){
  int s;
  if( p->validHMS ) return;
  computeJD(p);
  s = (int)(((int)p->iJD + 43200000)%86400000);
  p->s = s/1000.0;
  s = (int)p->s;
  p->s -= s;
  p->h = s/3600;
  s -= p->h*3600;
  p->m = s/60;
  p->s += s - p->m*60;
  p->validHMS = 1;
}



int main(){

    //char *zDate = "11:40";
    ///yyyy:mm:dd hh:mm:ss.mili   +/-hh:mm
    char *zDate = "2018-10-09 11:39:43.342   -11:37 ";
    //string str;
    //scanf("%s",str);

    //zDate[12]='/0';
    int nHr,nMn;

    /*if( getDigits(zDate, 2, 0, 14, ':', &nHr, 2, 0, 59, 0, &nMn)!=2 ){
            printf("\n No sir I cannot access there \n");

    }else{

        printf("nHr  %d\n  nMn  %d\n  YES\n",nHr,nMn);

    }*/
    DateTime *p = malloc(sizeof(DateTime));
    int n = parseYyyyMmDd(zDate, p);


    printf(" hour %d\n minutes %d\n s.mili  %lf\n tz  %d\n",p->h,p->m,p->s,p->tz);
    computeJD(p);

    printf("julian %lf\n",p->iJD);
    computeYMD(p);
    printf(" year %d\n months %d\n day  %d\n",p->Y,p->M,p->D);
    computeHMS(p);
    printf(" hour %d\n minutes %d\n s.mili  %lf\n tz  %d\n",p->h,p->m,p->s,p->tz);




return 0;
}
