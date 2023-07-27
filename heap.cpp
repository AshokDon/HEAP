#include <bits/stdc++.h>
#define fast_io ios_base::sync_with_stdio(false);cin.tie(NULL)
#define ll long long
#define pb push_back
using namespace std;
//const int mod = (int)1e9 + 7;
void TakeInput(){
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
//creat a Heap class 
class Heap{
private:
    vector<int>heap;//container 
    int left(int parent);//to get the left child
    int right(int parent);//to get the right child;
    int par(int child);//to get the child of the parent
    void heapifyup(int index);//to arrange the data in form of maxheap
    void heapifydown(int index);
public:
    Heap(){}
    void Insert(int data);//insert the data into heap DS
    void DeleteMax();//delete the data from heap DS
    int GetMax();//whill give the max value
    void Show(); //dislay the data which is in heap
    int Size();

};
int main() {
    // your code goes here
    fast_io;
    TakeInput();
    Heap H;
    while(1){
        cout<<"1.Insert the Element"<<endl;
        cout<<"2.Delete the Element"<<endl;
        cout<<"3.Extract the Max"<<endl;
        cout<<"4.show the heap"<<endl;
        cout<<"5.Exit"<<endl;
        int c , e;
        cin >> c >> e;
        switch(c){
            case 1:
                cout<<"Enter the element to be Inserted"<<endl;
                cin >> e;
                H.Insert(e);
                break;
            case 2:
                H.DeleteMax();
                break;
            case 3:
                if(H.GetMax()==-1){
                    cout<<"No data"<<endl;
                }
                else cout<<H.GetMax()<<endl;
                break;
            case 4:
                H.Show();
                break;
            case 5:
                exit(1);
                default:
                    cout<<"enter the correct choice"<<endl; 
        }

    }
    return 0;
}
int Heap::Size()
{
    return heap.size();
}
void Heap::Insert(int data){
    heap.pb(data);
    heapifyup(heap.size()-1);
}
void Heap::DeleteMax(){
    if(heap.size()==0){
        cout<<"Heap is Empty"<<endl;
        return;
    }
    heap[0] = heap[heap.size()-1];
    heap.pop_back();
    heapifydown(0);

}
int Heap::GetMax(){
    if(heap.size()==0){
        cout<<"no data"<<endl;
        return -1;
    }
    else return heap.front();
}
void Heap::Show(){
    vector<int>::iterator it = heap.begin();
    while(it!=heap.end()){
        cout<<*it<<" ";
        it++;
    }
    cout<<endl;
}
int Heap::left(int ele){
    int l = 2*ele+1;
    if(l < heap.size())return l;
    else return -1;
}
int Heap::right(int ele){
    int r = 2*ele+2;
    if(r < heap.size())return r;
    else return -1;
}
int Heap::par(int child){
    int p = (child-1)/2;
    if(child==0)return -1;
    else return p;
}
void Heap::heapifyup(int ind){
    if(ind >= 0 && par(ind)>=0 && heap[par(ind)] < heap[ind]){
        swap(heap[par(ind)],heap[ind]);
        heapifyup(par(ind));
    }
}
void Heap::heapifydown(int ind){
    int lar = ind;
    int l = left(ind);
    int r = right(ind);
    if(l < heap.size() and heap[l] > heap[ind]){
        lar = l;
    }
    if(r < heap.size() and heap[r] < heap[lar]){
        lar = r;
    }
    if(lar!=ind){
        swap(heap[lar],heap[ind]);
        heapifydown(lar);
    }
}







