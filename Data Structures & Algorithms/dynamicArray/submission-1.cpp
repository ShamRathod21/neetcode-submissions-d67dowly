class DynamicArray {
public:
    int capacity;
    int limit = 0;
    int *arr;
    DynamicArray(int capacity) {
        this->capacity = capacity;
        arr = (int *)malloc(capacity*sizeof(int));
    }

    int get(int i) {
        return arr[i];
    }

    void set(int i, int n) {
        arr[i] = n;
    }

    void pushback(int n) {
        if(limit == capacity) {
            resize();
        }
        arr[limit] = n;
        limit++;
    }

    int popback() {
       
        limit--;
         int back = arr[limit];
        return back;
    }

    void resize() {
        arr = (int *)realloc(arr, (capacity*2)*sizeof(int));
        capacity *= 2;
    }

    int getSize() {
        return limit;
    }

    int getCapacity() {
        return capacity;
    }
};
