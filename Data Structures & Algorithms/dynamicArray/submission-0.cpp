class DynamicArray {
public:
    DynamicArray(int capacity): capacity(capacity), size(0) {
        data = new int[capacity];
    }

    int get(int i) {
        return data[i];
    }

    void set(int i, int n) {
        if (i >= capacity) {
            resize();
        }
        data[i] = n;
    }

    void pushback(int n) {
        if (size == capacity) {
            resize();
        }
        data[size] = n;
        ++size;
    }

    int popback() {
        if (size > 0) {
            --size;
        }
        return data[size];
    }

    void resize() {
        capacity *= 2;
        int* newData = new int[capacity];
        for(int i = 0; i < size; ++i) {
            newData[i] = data[i];
        }
        delete[] data;
        data = newData;
    }

    int getSize() {
        return size;
    }

    int getCapacity() {
        return capacity;
    }
private:
    int* data;
    int capacity;
    int size;
};
