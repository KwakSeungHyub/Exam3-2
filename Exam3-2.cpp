#include <iostream>
#include <stdexcept>
#include <algorithm>
// 템플릿 클래스로 특정 타입(T)에 대해 작동하는 벡터를 정의
template <typename T>
class SimpleVector {
private:
    T* data;           // 템플릿 타입의 데이터를 저장할 배열
    size_t capa_1;     // 배열의 최대 크기 (capacity)
    size_t size_1;     // 현재 저장된 원소의 개수 (size)

public:
    // 생성자: 기본값으로 크기 10인 배열을 생성 (capacity를 전달받을 수도 있음)
    SimpleVector(size_t capacity = 10)
        : data(new T[capacity]), capa_1(capacity), size_1(0) {
    }

    // 소멸자: 동적 메모리 해제
    ~SimpleVector() {
        delete[] data;
    }

    // push_back: 배열의 맨 끝에 원소를 추가
    void push_back(const T& element) {
        if (size_1 >= capa_1) {
            // 새로운 용량 할당(최대치를 넘어가면 +5)
            size_t new_capacity = capa_1 + 5;
            T* new_data = new T[new_capacity];

            // 기존 데이터를 복사
            for (size_t i = 0; i < size_1; ++i) {
                new_data[i] = data[i];
            }

            // 기존 메모리 해제 및 교체
            delete[] data;
            data = new_data;
            capa_1 = new_capacity;
        }

        // 데이터 추가
        data[size_1++] = element;
    }
    // resize: 정수 하나를 받아 현재 사이즈보다 작을 경우 -> 아무 동작 x 클 경우 -> 해당 값만큼 크기를 재 할당
    void resize(const T& size) {
        //클 경우에는 해당 값만큼 크기를 재 할당
        if (size > capa_1) {
            // 새로운 용량 할당(최대치를 넘어가면 +5)
            size_t new_capacity = size;
            T* new_data = new T[size];

            // 기존 데이터를 복사
            for (size_t i = 0; i < size; ++i) {
                new_data[i] = data[i];
            }

            // 기존 메모리 해제 및 교체
            delete[] data;
            data = new_data;
            capa_1 = new_capacity;
        }
        else { // 작을경우는 아무 동작 X
        }
    }
    // sortData: 내부 데이터를 정렬 하는 함수(직접 정렬 X STL sort 함수 사용)
    void sortData() {
        std::sort(data, data + size_1); // 시작과 끝 포인터 전달
    }
    // pop_back: 배열의 맨 끝 원소를 제거
    void pop_back() {
        if (size_1 > 0) {
            --size_1; // size_1을 감소시켜 마지막 원소 제거
        }
    }

    // size: 현재 저장된 원소의 개수를 반환
    size_t size() const {
        return size_1;
    }

    // capacity: 배열의 최대 크기를 반환
    size_t capacity() const {
        return capa_1;
    }

    // operator[]: 배열처럼 원소를 인덱스를 통해 접근 (쓰기 가능)
    T& operator[](size_t index) {
        if (index >= size_1) {
            throw std::out_of_range("벡터 사이즈보다 큽니다");
        }
        return data[index];
    }

    // const operator[]: const 버전의 인덱스 접근 (읽기 전용)
    const T& operator[](size_t index) const {
        if (index >= size_1) {
            throw std::out_of_range("벡터 사이즈보다 큽니다.");
        }
        return data[index];
    }
};

// main 함수: SimpleVector 클래스의 동작 확인
int main() {
    // int 타입의 SimpleVector 생성 (기본 크기 10)
    SimpleVector<int> vec;
    std::cout << "인자값이 10개를 넘기 전, 최대 사이즈는: " << vec.capacity() << std::endl;
    // 벡터에 원소 추가
    for (size_t i = 0; i < 11; ++i) {
        int a = abs(rand() % 45);
        vec.push_back(a);
    }
    std::cout << "인자값이 10개를 넘은 이후, 최대 사이즈는: " << vec.capacity() << std::endl;
    std::cout << "resize 실행 이전, 최대 사이즈는: " << vec.capacity() << std::endl;
    vec.resize(20);
    // 벡터 원소 출력
    std::cout << "벡터의 원소들: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "resize 실행 이후, 최대 사이즈는: " << vec.capacity() << std::endl;
    
    // 벡터 원소 출력
    std::cout << "벡터의 원소들: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "pop_back 실행 이전, 사이즈는: " << vec.size() << std::endl;
    // 맨 끝 원소 제거
    vec.pop_back();
    std::cout << "pop_back 실행 이후, 사이즈는: " << vec.size() << std::endl;
    std::cout << "sort Data 전 벡터의 원소들: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    } 
    std::cout << std::endl;
    vec.sortData();
    std::cout << "sort Data 후 벡터의 원소들: ";
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << std::endl;
    // double 타입의 SimpleVector 생성 (크기 5)
    SimpleVector<double> doubleVec(5);

    doubleVec.push_back(1.14);
    doubleVec.push_back(5.71);
    doubleVec.push_back(8.87);
    doubleVec.push_back(6.74);
    doubleVec.push_back(7.14);
    doubleVec.push_back(16.14);
    doubleVec.push_back(19.14);

    std::cout << "doubleVec의 최대 사이즈는: " << doubleVec.capacity() << std::endl;
    // double 벡터 원소 출력
    std::cout << "sortData 전 Double Vector의 원소들: ";
    for (size_t i = 0; i < doubleVec.size(); ++i) {
        std::cout << doubleVec[i] << " ";
    }
    std::cout << std::endl;
    doubleVec.sortData();
    std::cout << "sortData 후 Double Vector의 원소들: ";
    for (size_t i = 0; i < doubleVec.size(); ++i) {
        std::cout << doubleVec[i] << " ";
    }
    std::cout << std::endl;
    return 0;
}