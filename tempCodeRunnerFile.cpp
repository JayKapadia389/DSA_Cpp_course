 temp = arr[i+1];
        arr[i+1] = arr[l];
        arr[l] = temp;

        return i+1;