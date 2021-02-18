// 클래스 예제
function greeter(person: string): string {
    return "Hello, "+person;
}

let user: string = 'jane User';

// 인터페이스 예제
interface Person {
    firstName: string;
    lastName: string;
}

function greeter2(person: Person) {
    return "Hello, "+ person.firstName + " " + person.lastName;
}

let user2 = { firstName: "Min", lastName:"Byeong Chan"};

// 클래스 예제2
// public 이란 키워드는 해당 인수를 Student의 프로퍼티를 자동으로 생성한다는 축양형!
class Student {
    fullName: string;
    constructor(public firstName: string, public middleInitial: string, public lastName: string) {
        this.fullName = firstName + " "+ middleInitial + " " + lastName;
    }
}

let user3 = new Student("Min", "Byeong Chan", "User");
// 결과 : user3: {firstName: "Min", middleInitial: "Byeong Chan", lastName: "User", fullName: "Min Byeong Chan User"}
console.log(user3);

/////////////////////////////////////////////

class Greeter {
    greeting: string;
    constructor(message: string) {
        this.greeting = message;
    }

    greet() {
        return "Hello, "+ this.greeting;
    }
}

let a = new Greeter('world');
console.log(a);

class Animal {
    name: string;
    constructor(theName: string) {
        this.name = theName;
    }
    move(distanceInMeters: number = 0) {
        console.log(`Animal moved ${distanceInMeters} m.`);
    }
}

class Dog extends Animal {
    bark = () => {
        console.log(('Woof! Woof!'))
    }
}

class Snake extends Animal {
    constructor(name: string) {
        super(name);
    }
    move(distanceInMeters = 5) {
        console.log('Slithering...');
        super.move(distanceInMeters);
    }
}

class Horse extends Animal {
    constructor(name: string) { super(name); }
    move(distanceInMeters = 45) {
        console.log('Galloping...')
        super.move(distanceInMeters);
    }
}

let sam = new Snake('SANSANSAN')
let tom: Animal = new Horse("TOMTOMTOMTOM")

sam.move();
tom.move(34);

//Public, private 그리고 protected 지정자

