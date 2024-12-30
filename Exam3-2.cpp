#include <iostream>
#include <stdexcept>
#include <algorithm>
// ���ø� Ŭ������ Ư�� Ÿ��(T)�� ���� �۵��ϴ� ���͸� ����
template <typename T>
class SimpleVector {
private:
    T* data;           // ���ø� Ÿ���� �����͸� ������ �迭
    size_t capa_1;     // �迭�� �ִ� ũ�� (capacity)
    size_t size_1;     // ���� ����� ������ ���� (size)

public:
    // ������: �⺻������ ũ�� 10�� �迭�� ���� (capacity�� ���޹��� ���� ����)
    SimpleVector(size_t capacity = 10)
        : data(new T[capacity]), capa_1(capacity), size_1(0) {
    }

    // �Ҹ���: ���� �޸� ����
    ~SimpleVector() {
        delete[] data;
    }

    // push_back: �迭�� �� ���� ���Ҹ� �߰�
    void push_back(const T& element) {
        if (size_1 >= capa_1) {
            // ���ο� �뷮 �Ҵ�(�ִ�ġ�� �Ѿ�� +5)
            size_t new_capacity = capa_1 + 5;
            T* new_data = new T[new_capacity];

            // ���� �����͸� ����
            for (size_t i = 0; i < size_1; ++i) {
                new_data[i] = data[i];
            }

            // ���� �޸� ���� �� ��ü
            delete[] data;
            data = new_data;
            capa_1 = new_capacity;
        }

        // ������ �߰�
        data[size_1++] = element;
    }
    // resize: ���� �ϳ��� �޾� ���� ������� ���� ��� -> �ƹ� ���� x Ŭ ��� -> �ش� ����ŭ ũ�⸦ �� �Ҵ�
    void resize(const T& size) {
        //Ŭ ��쿡�� �ش� ����ŭ ũ�⸦ �� �Ҵ�
        if (size > capa_1) {
            // ���ο� �뷮 �Ҵ�(�ִ�ġ�� �Ѿ�� +5)
            size_t new_capacity = size;
            T* new_data = new T[size];

            // ���� �����͸� ����
            for (size_t i = 0; i < size; ++i) {
                new_data[i] = data[i];
            }

            // ���� �޸� ���� �� ��ü
            delete[] data;
            data = new_data;
            capa_1 = new_capacity;
        }
        else { // �������� �ƹ� ���� X
        }
    }
    // sortData: ���� �����͸� ���� �ϴ� �Լ�(���� ���� X STL sort �Լ� ���)
    void sortData() {
        std::sort(data, data + size_1); // ���۰� �� ������ ����
    }
    // pop_back: �迭�� �� �� ���Ҹ� ����
    void pop_back() {
        if (size_1 > 0) {
            --size_1; // size_1�� ���ҽ��� ������ ���� ����
        }
    }

    // size: ���� ����� ������ ������ ��ȯ
    size_t size() const {
        return size_1;
    }

    // capacity: �迭�� �ִ� ũ�⸦ ��ȯ
    size_t capacity() const {
        return capa_1;
    }

    // operator[]: �迭ó�� ���Ҹ� �ε����� ���� ���� (���� ����)
    T& operator[](size_t index) {
        if (index >= size_1) {
            throw std::out_of_range("���� ������� Ů�ϴ�");
        }
        return data[index];
    }

    // const operator[]: const ������ �ε��� ���� (�б� ����)
    const T& operator[](size_t index) const {
        if (index >= size_1) {
            throw std::out_of_range("���� ������� Ů�ϴ�.");
        }
        return data[index];
    }
};

// main �Լ�: SimpleVector Ŭ������ ���� Ȯ��
int main() {
    // int Ÿ���� SimpleVector ���� (�⺻ ũ�� 10)
    SimpleVector<int> vec;
    std::cout << "���ڰ��� 10���� �ѱ� ��, �ִ� �������: " << vec.capacity() << std::endl;
    // ���Ϳ� ���� �߰�
    for (size_t i = 0; i < 11; ++i) {
        int a = abs(rand() % 45);
        vec.push_back(a);
    }
    std::cout << "���ڰ��� 10���� ���� ����, �ִ� �������: " << vec.capacity() << std::endl;
    std::cout << "resize ���� ����, �ִ� �������: " << vec.capacity() << std::endl;
    vec.resize(20);
    // ���� ���� ���
    std::cout << "������ ���ҵ�: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "resize ���� ����, �ִ� �������: " << vec.capacity() << std::endl;
    
    // ���� ���� ���
    std::cout << "������ ���ҵ�: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "pop_back ���� ����, �������: " << vec.size() << std::endl;
    // �� �� ���� ����
    vec.pop_back();
    std::cout << "pop_back ���� ����, �������: " << vec.size() << std::endl;
    std::cout << "sort Data �� ������ ���ҵ�: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    } 
    std::cout << std::endl;
    vec.sortData();
    std::cout << "sort Data �� ������ ���ҵ�: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    // double Ÿ���� SimpleVector ���� (ũ�� 5)
    SimpleVector<double> doubleVec(5);

    doubleVec.push_back(1.14);
    doubleVec.push_back(5.71);
    doubleVec.push_back(8.87);
    doubleVec.push_back(6.74);
    doubleVec.push_back(7.14);
    doubleVec.push_back(16.14);
    doubleVec.push_back(19.14);

    std::cout << "doubleVec�� �ִ� �������: " << doubleVec.capacity() << std::endl;
    // double ���� ���� ���
    std::cout << "sortData �� Double Vector�� ���ҵ�: ";
    for (size_t i = 0; i < doubleVec.size(); ++i) {
        std::cout << doubleVec[i] << " ";
    }
    std::cout << std::endl;
    doubleVec.sortData();
    std::cout << "sortData �� Double Vector�� ���ҵ�: ";
    for (size_t i = 0; i < doubleVec.size(); ++i) {
        std::cout << doubleVec[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}