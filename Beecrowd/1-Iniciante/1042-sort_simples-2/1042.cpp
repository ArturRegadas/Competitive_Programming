
#include <iostream>


void merge(int array[], int left, int midle, int right, int size){

    int aux[right - left];
    int auxI = 0;
    midle++;

    int initLeft = left;
    int initRight = right;
    int initMidle = midle;


    while(left <= initMidle && midle <= right){
        if(array[left]<array[midle]){
            aux[auxI] = array[left];
            left++;

        }
        else{
            aux[auxI] = array[midle];
            midle++;
            
        }
        auxI++;
    }
    for(int i = left; i<= initMidle; i++){
        aux[auxI] = array[i];
        auxI++;
    }

    for(int i = midle; i<= right; i++){
        aux[auxI] = array[i];
        auxI++;
    }
    int index = 0;
    for(int i = initLeft; i<= initRight; i++){
        array[i] = aux[index];
        index++;
    }

}


void mergesort(int array[],int left, int right, int size){
    
    if(left<right){

        int midle = left+(right - left)/ 2;
        mergesort(array, left, midle, size);
        mergesort(array, midle+1, right, size);


        
        merge(array, left, midle, right, size);
    }
    
}



int main(){

    int nums[3];
    int nww[3];
    int a;
    for(int i =0; i<3; i++){
        std::cin>>a;
        nums[i] = a;
        nww[i]=a;
    }

    mergesort(nums, 0, 2, 3);
    for(int i =0; i<3; i++){
        std::cout<<nums[i]<<"\n";
    }
    std::cout<<"\n";
    for(int i =0; i<3; i++){
        std::cout<<nww[i]<<"\n";
    }


    return 0;
}

