#ifndef SINGLETON_HPP
#define SINGLETON_HPP

/*
 * 싱글톤(Singleton) 패턴은 오직 하나의(싱글) 인스턴스만 허용하는 패턴이다.
 * 여러가지 구현 방법이있지만 static 변수를 통한 방법이 대부분이다.
 * 그보다 아직 static을 이용하지 않은 방법을 보지 못했다.
 */
 
/*
 * 거의 모든 디자인패턴 책에서 소개되는 패턴이지만 싱글톤은 욕을 많이 먹는다.
 * 이유는 thread-safe 하지 못하다는 것이다.
 * 그래서 최대한 스레드에 안전하면서도 이해되는 코드를 찾아보았다.
 */
 
class Singleton
{
public:
    static Singleton& getInstance()
    {
        static Singleton instance;
        return instance;
    }
    
    // 오직 하나의 인스턴스만을 허용하기 때문에 대부분의 기타 생성자는 필요로하지 않는다.
    // 따라서 복사, 이동 생성자 및 복사, 이동 할당연사자를 제거한다.
    Singleton(Singleton const&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(Singleton const&) = delete;
    Singleton& operator=(Singleton &&) = delete;  
    
protected:
    Singleton() {} // 명시적으로 생성자를 호출하는 것을 막기 위해 protected로 접근레벨을 낮추었다.
    ~Singleton() {}
private:
  
};

#endif