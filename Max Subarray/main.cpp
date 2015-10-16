#include <iostream>

using namespace std;

int* maxSubarray(int size, int* returnedArraySize, int* array);

int* maxMiddlearray(int size, int* returnedArraySize, int* array);

int main()
{
    int size;
    cout << "Please enter the size of the array" << endl;
    cin >> size;
    int array[size];
    int* p_array = array;
    for(int i = 0; i < size; i ++){
        cout << "please enter the " << i + 1 << " element" << endl;
        cin >> array[i];
    }
    int* p_returnedArraysize = new int;
    int* returnedArray = maxSubarray(size, p_returnedArraysize, p_array);
    cout << "max array is:\n" << "[ ";
    for(int i = 0; i < *p_returnedArraysize; i++){
        cout << *(returnedArray + i) << " ";
    }
    cout << "]" << endl;
    return 0;
}

int* maxSubarray(int size, int* returnedArraySize, int* array)
{
    if(size <= 1){
        *returnedArraySize = size;
        return array;
    }
    int leftSize = size / 2;
    int rightSize = size - leftSize;
    int* leftArray = new int[leftSize];
    int* rightArray = new int[rightSize];
    int leftSum = 0;
    int rightSum = 0;
    int middleSum = 0;
    int i = 0;
    for(; i < leftSize; i++){
        leftArray[i] = *(array + i);
    }
    for(; i < size; i++){
        rightArray[i - leftSize] = *(array + i);
    }
    int* p_middleReturnedSize = new int(0);
    int* p_leftReturnedSize = new int(0);
    int* p_rightReturnedSize = new int(0);
    int* p_middleMax = maxMiddlearray(size, p_middleReturnedSize, array);
    int* p_leftMax = maxSubarray(leftSize, p_leftReturnedSize, leftArray);
    int* p_rightMax = maxSubarray(rightSize, p_rightReturnedSize, rightArray);
    cout << "the returned arrays: " << endl;
    cout << " left: [ ";
    for(int i = 0; i < *p_leftReturnedSize; i++){
        leftSum += *(p_leftMax + i);
        cout << p_leftMax[i] << " ";
    }
    cout << "]" << endl;
    cout << " right: [ ";
    for(int i = 0; i < *p_rightReturnedSize; i++){
        rightSum += *(p_rightMax + i);
        cout << p_rightMax[i] << " ";
    }
    cout << "]" << endl;
    cout << " middle: [ ";
    for(int i = 0; i < *p_middleReturnedSize; i++){
        middleSum += p_middleMax[i];
        cout << p_middleMax[i] << " ";
    }
    cout << "]" << endl;
    if(leftSum >= rightSum && leftSum > middleSum){
        *returnedArraySize = *p_leftReturnedSize;
        return p_leftMax;
    }else
    if(rightSum > leftSum && rightSum >= middleSum){
        *returnedArraySize = *p_rightReturnedSize;
        return p_rightMax;
    }else
    if(middleSum >= leftSum && middleSum > rightSum){
        *returnedArraySize = *p_middleReturnedSize;
        return p_middleMax;
    }
    return NULL;
}

int* maxMiddlearray(int size, int* returnedArraySize, int* array)
{
    int leftBound = 0;
    int leftMax = -100000;
    int leftSum = 0;
    int rightBound = 0;
    int rightMax = -100000;
    int rightSum = 0;
    for(int i = size / 2 - 1; i >= 0; i --){
        leftSum += *(array + i);
        if(leftSum > leftMax){
            leftBound = i;
            leftMax = leftSum;
        }
    }
    for(int i = size / 2; i < size; i ++){
        rightSum += *(array + i);
        if(rightSum > rightMax){
            rightBound = i;
            rightMax = rightSum;
        }
    }
    *returnedArraySize = rightBound - leftBound + 1;
    int* p_newArray = new int[*returnedArraySize];
    for(int i = 0; i < *returnedArraySize; i++){
        p_newArray[i] = *(array + i + leftBound);
    }
    return p_newArray;
}
