#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

//strategy Interface
class SortingStrategy{
public:
    //pure virtual function
    virtual void sort(vector<int>& vec)=0;

    //virtual destructor
    virtual ~SortingStrategy() {}
};

//concrete strategies: bubble, quick and merge sort
class BubbleSortStrategy : public SortingStrategy
{
    public:
        void sort(vector<int>& vec) override{
            cout<<"sorting through bubble sort strategy!"<<endl;
            //here goes the actual implementation for algorithm
        }
};
class QuickSortStrategy : public SortingStrategy
{
    public:
        void sort(vector<int>& vec) override{
            cout<<"sorting through quick sort strategy!"<<endl;
            //here goes the actual implementation for algorithm
        }
};
class MergeSortStrategy : public SortingStrategy
{
    public:
        void sort(vector<int>& vec) override{
            cout<<"sorting through Merge sort strategy!"<<endl;
            //here goes the actual implementation for algorithm
        }
};

//context
class SortingContext{
    private:
        SortingStrategy* sortingStrategy;
    public:
        //constructor
        SortingContext(SortingStrategy* strategy)
        {
            this->sortingStrategy = strategy;
        }
        //setter to change strategy
        void setSortingStrategy(SortingStrategy* strategy)
        {
            this->sortingStrategy = strategy;
        }
        //perform sort
        void performSort(vector<int>& vec)
        {
            if(sortingStrategy)
            {
                sortingStrategy->sort(vec);
            }
        }
};

int main()
{
    //create strategies
    SortingStrategy* bubble = new BubbleSortStrategy();
    SortingStrategy* quick = new QuickSortStrategy();
    SortingStrategy* merge = new MergeSortStrategy();

    //create sorting context with bubble strategy
    SortingContext context(bubble);
    vector<int> arr = {4, 7, 45, 23, 80, 20};
    context.performSort(arr);

    //change to merge sort strategy;
    context.setSortingStrategy(merge);
    vector<int> arr2 = {45, 66, 24, 68, 59};
    context.performSort(arr2);

    //change to merge sort strategy;
    context.setSortingStrategy(merge);
    vector<int> arr3 = {12, 234, 2345, 682, 539};
    context.performSort(arr3);
    delete bubble;
    delete merge;
    delete quick;
    return 0;
};