#include<stdio.h>
#include<fstream>
#include<string>

typedef  struct GlobalHeader{

    //24 bytes

    unsigned int GlobalHeader;
    unsigned short MajorVersionNumber;
    unsigned short MinorVersionNUmber;
    unsigned int GMTTimeOffset;
    unsigned int sigfigs;
    unsigned int MaximumSnapLength;
    unsigned int LinkLayerProtocol;

};

typedef struct hexdump{


    /*
        here we convert char to int to find time
        and find length of the packet
    */

    unsigned int timestamp[4];            ///seconds since the start of 1970
    unsigned int PacketCapturedTime[4];  ///when the packet is captured
    unsigned int LengthOfThePacket[4];
    unsigned int Savedata[4];
    /*
        packet length without (Grobalheader+hexdump)(means 40 bytes)

    */
};

typedef struct EthernetHeader{

    unsigned char DestinationAddress[6];
    unsigned char SourceAddress[6];
    unsigned short int TypeOfPacket[2];///find it is IPv4/IPv6
};

typedef struct ARPHeader{

    unsigned short int HardwareType;
    unsigned short int ProtocolType;
    char HardwareLen;
    char ProtocolLen;
    unsigned short int Opcode;
    char SourceMacaddress[6];
    char SourceIP[4];
    char DestinationMacaddress[6];
    char DestinationIP[4];

};

typedef struct IPv4Header{

    ///24 bytes;

    char VersionType;  ///0x45 -->IPv4 0x60 --> IPv6
    char DifferentiateServiceField;
    unsigned int TotalLength;  /// packetSize-14(Ethernet);
    unsigned int IdentificationLength;
    char StoreFlags;
    char FragmentOffset;
    char timeTolive;
    char protocol;
    unsigned short int CheckSum;
    char  SourceIPaddress[4];
    char DestinationIPaddress[4];

};

typedef struct UDPheader{

    char SourcePort[2];
    char DestinationPort[2];
    unsigned short int lengthField;   ///udp header+rest of the payload;
    char checkSum[2];

};

typedef struct ICMP{

    char typeOfICPM;
    char code;        ///45 types of code in ICMP;
    char checkSum[2];
    char Identifier[2];
    char sequence[2];

};

typedef struct TCP{

    char SourcePort[2];
    char DestinationPort[2];
    char SequenceNumber[4];
    char AcknowledgeNumber[4];
    char Flags[2];
    unsigned short int windowSize;
    char checkSum[2];
    char urgentPointer[2];


};

int getVal(char c)
   {
       int rtVal = 0;

       if(c >= '0' && c <= '9')
       {
           rtVal = c - '0';
       }
       else
       {
           rtVal = c - 'a' + 10;
       }

       return rtVal;
}

int main(){

    FILE *fp;
    int cn=0;
    int  bcn=0;
    unsigned char ch;
    unsigned char arr[16];
    int i=0,t=0;
    double k=0;
    int time[40];

    fp = fopen("sai.pcap","rb");

    while(!feof(fp)){

        fread(&ch,1,1,fp);
        printf("%.02x ",ch&(0xff));
        bcn++;

        if(bcn==132)printf("  \n\n\n\n  ");
        else if(bcn==240)printf("  \n\n\n\n  ");
        else if(bcn==348)printf("  \n\n\n\n  ");
        else if(bcn==406)printf("  \n\n\n\n  ");
        else if(bcn==482)printf("  \n\n\n\n  ");
        else if(bcn==574)printf("  \n\n\n\n  ");
        else if(bcn==666)printf("  \n\n\n\n  ");
        else if(bcn==758)printf("  \n\n\n\n  ");
        else if(bcn==918)printf("  \n\n\n\n  ");
        else if(bcn==1020)printf("  \n\n\n\n  ");
        else if(bcn==1122)printf("  \n\n\n\n  ");
        else if(bcn==1224)printf("  \n\n\n\n  ");
        else if(bcn==1300)printf("  \n\n\n\n  ");
        else if(bcn==1358)printf("  \n\n\n\n  ");
        else if(bcn==1460)printf("  \n\n\n\n  ");
        else if(bcn==1562)printf("  \n\n\n\n  ");
        else if(bcn==1660)printf("  \n\n\n\n  ");
        else if(bcn==1781)printf("  \n\n\n\n  ");
        else if(bcn==2306)printf("  \n\n\n\n  ");


       /* arr[i]=(char)ch;
        i++;
        k++;

        if(k>=25 && k<=40){
            time[t]=(int)ch;
            t++;
        }

        if(i%8==0)printf("   ");
        if(i%16==0){
            for(int j=0;j<16;j++){
                if(isprint(arr[j]))
                    printf("%c", (char)arr[j]);
               else
                    printf(".");
            }
            cn++;
            //cout<<"  line no "<<cn;
            printf("  line no %d  %d",cn,bcn);
            printf(" \n");

            i=0;


        }*/
    }

    fclose(fp);
    printf(" \n");
    for(t=0;t<16;t++)
        printf("%d  ",time[t]);

return 0;
}
