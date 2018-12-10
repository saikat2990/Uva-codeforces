// C program for Huffman Coding
#include <stdio.h>
#include <stdlib.h>
#include<bits/stdc++.h>
// This constant can be avoided by explicitly
// calculating height of Huffman Tree
#define MAX_TREE_HT 100

using namespace std;
// A Huffman tree node


struct s{

    char ch;
    string code;
    int codeLen;

};

vector<s>store;

string ss(int n){

    stringstream iss;
    iss<<n;
    string str;
    iss>>str;
    return str;
}

vector<char>check;

void charToBinary(char c) {

    for (int i = 7; i >= 0; --i) {

         check.push_back(((c & (1 << i))? '1' : '0'));
    }

}

int binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;

    // Initializing base value to 1, i.e 2^0
    int base = 1;

    int temp = num;
    while (temp)
    {
        int last_digit = temp % 10;
        temp = temp/10;

        dec_value += last_digit*base;

        base = base*2;
    }

    return dec_value;
}

string charToString(char ch){

    stringstream iss;
    string sr;
    iss<<ch;
    iss>>sr;
    return sr;
}

int stringToNum(string ch){

    stringstream iss;
    int sr;
    iss<<ch;
    iss>>sr;
    return sr;
}

struct MinHeapNode {

    char data;

    unsigned freq;

    struct MinHeapNode *left, *right;
};


struct MinHeap {

    unsigned size;

    unsigned capacity;

    struct MinHeapNode** array;
};

struct MinHeapNode* newNode(char data, unsigned freq)
{
    struct MinHeapNode* temp
        = (struct MinHeapNode*)malloc
(sizeof(struct MinHeapNode));

    temp->left = temp->right = NULL;
    temp->data = data;
    temp->freq = freq;

    return temp;
}

struct MinHeap* createMinHeap(unsigned capacity)

{

    struct MinHeap* minHeap
        = (struct MinHeap*)malloc(sizeof(struct MinHeap));

    minHeap->size = 0;

    minHeap->capacity = capacity;

    minHeap->array
        = (struct MinHeapNode**)malloc(minHeap->
capacity * sizeof(struct MinHeapNode*));
    return minHeap;
}

void swapMinHeapNode(struct MinHeapNode** a,
                     struct MinHeapNode** b)

{

    struct MinHeapNode* t = *a;
    *a = *b;
    *b = t;
}

void minHeapify(struct MinHeap* minHeap, int idx)

{

    int smallest = idx;
    int left = 2 * idx + 1;
    int right = 2 * idx + 2;

    if (left < minHeap->size && minHeap->array[left]->
freq < minHeap->array[smallest]->freq)
        smallest = left;

    if (right < minHeap->size && minHeap->array[right]->
freq < minHeap->array[smallest]->freq)
        smallest = right;

    if (smallest != idx) {
        swapMinHeapNode(&minHeap->array[smallest],
                        &minHeap->array[idx]);
        minHeapify(minHeap, smallest);
    }
}

int isSizeOne(struct MinHeap* minHeap)
{

    return (minHeap->size == 1);
}

struct MinHeapNode* extractMin(struct MinHeap* minHeap)

{

    struct MinHeapNode* temp = minHeap->array[0];
    minHeap->array[0]
        = minHeap->array[minHeap->size - 1];

    --minHeap->size;
    minHeapify(minHeap, 0);

    return temp;
}

void insertMinHeap(struct MinHeap* minHeap,
                   struct MinHeapNode* minHeapNode)

{

    ++minHeap->size;
    int i = minHeap->size - 1;

    while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {

        minHeap->array[i] = minHeap->array[(i - 1) / 2];
        i = (i - 1) / 2;
    }

    minHeap->array[i] = minHeapNode;
}

void buildMinHeap(struct MinHeap* minHeap)

{

    int n = minHeap->size - 1;
    int i;

    for (i = (n - 1) / 2; i >= 0; --i)
        minHeapify(minHeap, i);
}

void printArr(int arr[], int n)
{
    int i;
    for (i = 0; i < n; ++i)
        printf("%d  ", arr[i]);

    printf("\n");
}

int isLeaf(struct MinHeapNode* root)

{

    return !(root->left) && !(root->right);
}

struct MinHeap* createAndBuildMinHeap(char data[], int freq[], int size)

{

    struct MinHeap* minHeap = createMinHeap(size);

    for (int i = 0; i < size; ++i)
        minHeap->array[i] = newNode(data[i], freq[i]);

    minHeap->size = size;
    buildMinHeap(minHeap);

    return minHeap;
}

struct MinHeapNode* buildHuffmanTree(char data[], int freq[], int size)

{
    struct MinHeapNode *left, *right, *top;

    struct MinHeap* minHeap = createAndBuildMinHeap(data, freq, size);

    while (!isSizeOne(minHeap)) {

        left = extractMin(minHeap);
        right = extractMin(minHeap);

        top = newNode('$', left->freq + right->freq);

        top->left = left;
        top->right = right;

        insertMinHeap(minHeap, top);
    }

    return extractMin(minHeap);
}

void printCodes(struct MinHeapNode* root, int arr[], int top)

{

    if (root->left) {

        arr[top] = 0;
        printCodes(root->left, arr, top + 1);
    }

    if (root->right) {

        arr[top] = 1;
        printCodes(root->right, arr, top + 1);
    }

    if (isLeaf(root)) {

        printf("%c:", root->data);
        printArr(arr, top);

        s temp;
        temp.ch = root->data;
        temp.code="";
        for (int i = 0; i < top; ++i){
            temp.code+=ss(arr[i]);
        }
        temp.codeLen = temp.code.length();
        store.push_back(temp);
       // temp.val = value(temp.code);
    }
}

void HuffmanCodes(char data[], int freq[], int size)
{

    struct MinHeapNode* root
        = buildHuffmanTree(data, freq, size);

    int arr[MAX_TREE_HT], top = 0;

    printCodes(root, arr, top);
}

int main()
{
    ifstream ifile;
    ifile.open("haffmantext.txt");

    ofstream ofile;
    ofile.open("compresstext.txt");

    char ch;
    char arr[256] ;
    int freq[256]={0},p=0 ;
    char flag [256]={false};
    string str;

    while(getline(ifile,str)){
        //cout<<ch;
        for(int i=0;i<str.length();i++){
            ch=str[i];
            arr[(int)ch] = ch;
            freq[(int)ch] = freq[(int)ch]+1;
            if(flag[(int)ch]==false){
                flag[(int)ch] = true;
                p++;
            }

        }
    }
    cout<<endl;
   // char arr[] = { 'a', 'b', 'c', 'd', 'e', 'f' };
    //int freq[] = { 5, 9, 12, 13, 16, 45 };

    int size = sizeof(arr) / sizeof(arr[0]);
     //vector<char>vec;
     char vec[p];
     int vecin[p];
     int k=0;
    for(int i=0;i<256;i++){
       // <<endl;
       if(freq[i]>0){
            vec[k]=(arr[i]);
            vecin[k] = freq[i];
            k++;
            cout<<arr[i]<<"----->"<<freq[i]<<"    "<<k<<endl;
        }
    }

   HuffmanCodes(vec, vecin, p);
    vector<s>:: iterator it;
    vector<char>ans;
     int n=0;
     //store=0,need=0,storeVal=0,useVal=0;
    ch=0;
    bool tag=false;
    vector<char>:: iterator c;
    ifile.close();

    ifstream ifile4;
    ifile4.open("haffmantext.txt");

    while(getline(ifile4,str)){
        //cout<<ch;
        for(int i=0;i<str.length();i++){
            ch=str[i];
            //cout<<ch;
            for(it=store.begin();it!=store.end();it++){

                s temp = *it;
                if(temp.ch==ch){
                    for(int i=0;i<temp.codeLen;i++){
                        ans.push_back(temp.code[i]);
                    }
                    break;
                }

            }
        }
    }

    //cout<<endl<<ans.size()<<endl;

    if(ans.size()%8!=0){
        cout<<endl<<ans.size()%8<<endl;
        for(int j=(ans.size()%8);j<8;j++){
            ans.push_back('0');
        }
    }else cout<<endl<<"0000000000"<<endl;

    string num="";
    int i=0;
    char ch1;

    for(c = ans.begin(); c!=ans.end();c++){
        //cout<<*c;
    }

    cout<<endl<<"ans size is"<<ans.size()<<endl;
    k=0;
    for(c = ans.begin(); c!=ans.end();c++){
        //cout<<*c;

        i++;
        num+=(charToString(*c));
        if(i%8==0){
            k++;
            ch1 = binaryToDecimal(stringToNum(num));
            //cout<<ch1;
            ofile<<ch1;
            num="";
        }
    }
    cout<<k<<endl;
    ifile.close();
    ofile.close();
    ///decompress
    ifstream ifile2;
    ifile2.open("compresstext.txt");
    char s1;
    k=0;
    str="";
    int n3 = ans.size();
    cout<<n3<<endl;
    //while(getline(ifile2,str)){
    while(ifile2>>s1){
        //cout<<ch;
        //ifile2>>s1;
        //cout<<str;
       // for(int i=0;i<str.length();i++){
            //s1=str[i];
            //cout<<s1;
            k++;
            charToBinary(s1);
       // }

        str="";
    }
    cout<<endl<<"compressed file size  "<<k<<endl;
    cout<<endl<<check.size()<<endl;
    cout<<"decompression"<<endl;
    ofstream ofile2;
    ofile2.open("decompresstext.txt");
    string val="";
    num="";
    k=0;
    char ct;

    for(c = ans.begin();c!=ans.end();c++){

        //cout<<*c;
        num+=(charToString(*c));
        for(it=store.begin();it!=store.end();it++){

            s temp;
            temp = *it;
            if(temp.code==num){
                ofile2<<temp.ch;
                //cout<<temp.ch;
                num="";
            }

        }

    }

    return 0;
}
