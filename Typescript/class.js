// // 클래스 예제
// function greeter(person: string): string {
//     return "Hello, "+person;
// }
// let user: string = 'jane User';
// // 인터페이스 예제
// interface Person {
//     firstName: string;
//     lastName: string;
// }
// function greeter2(person: Person) {
//     return "Hello, "+ person.firstName + " " + person.lastName;
// }
// let user2 = { firstName: "Min", lastName:"Byeong Chan"};
// // 클래스 예제2
// // public 이란 키워드는 해당 인수를 Student의 프로퍼티를 자동으로 생성한다는 축양형!
// class Student {
//     fullName: string;
//     constructor(public firstName: string, public middleInitial: string, public lastName: string) {
//         this.fullName = firstName + " "+ middleInitial + " " + lastName;
//     }
// }
// let user3 = new Student("Min", "Byeong Chan", "User");
// // 결과 : user3: {firstName: "Min", middleInitial: "Byeong Chan", lastName: "User", fullName: "Min Byeong Chan User"}
// console.log(user3);
// /////////////////////////////////////////////
// class Greeter {
//     greeting: string;
//     constructor(message: string) {
//         this.greeting = message;
//     }
//     greet() {
//         return "Hello, "+ this.greeting;
//     }
// }
// let a = new Greeter('world');
// console.log(a);
// class Animal {
//     name: string;
//     constructor(theName: string) {
//         this.name = theName;
//     }
//     move(distanceInMeters: number = 0) {
//         console.log(`Animal moved ${distanceInMeters} m.`);
//     }
// }
// class Dog extends Animal {
//     bark = () => {
//         console.log(('Woof! Woof!'))
//     }
// }
// class Snake extends Animal {
//     constructor(name: string) {
//         super(name);
//     }
//     move(distanceInMeters = 5) {
//         console.log('Slithering...');
//         super.move(distanceInMeters);
//     }
// }
// class Horse extends Animal {
//     constructor(name: string) { super(name); }
//     move(distanceInMeters = 45) {
//         console.log('Galloping...')
//         super.move(distanceInMeters);
//     }
// }
// let sam = new Snake('SANSANSAN')
// let tom: Animal = new Horse("TOMTOMTOMTOM")
// sam.move();
// tom.move(34);
// // 제네릭
// function identity<T>(arg: T): T {
//     return arg;
// }
// let output = identity<string>("myString");
// console.log(output);
// let myIdentity: {<U>(arg: U): U} = identity;
// interface GenericIdentityFn<T> {
//     <T>(arg: T): T;
// }
// function identity2<T>(arg: T):T {
//     return arg;
// }
// let myIdentity2: GenericIdentityFn<number> = identity2;
// // 제네릭 클래스
// class GenericNumber<T> {
//     zeroValue: T;
//     add: (x: T, y: T) => T;
// }
// let myGenericNumber = new GenericNumber<string>();
// myGenericNumber.zeroValue = "";
// myGenericNumber.add = function(x,y) { return x+y;} ;
// let stringNumeric = new GenericNumber<string>();
// stringNumeric.zeroValue = "";
// stringNumeric.add = function(x,y) {return x+ y;};
// console.log(stringNumeric.add(stringNumeric.zeroValue, "test"));
// // 제네릭을 사용할 때, .length라는 프로퍼티를 갖는 타입으로 타입을 제한하고 싶다.
// // 최소 length라는 멤버가 들어오면 length접근을 허용하고 아닐시 허용하지 않는다.
// // 그렇게 하기 위해 제약조건을 나열해야한다.
// // 제약조건은 인터페이스를 생성해 표현할 수 있다.
// interface Lengthwise {
//     length: number;
// }
// function loggingIdentity<T extends Lengthwise>(arg: T): T {
//     console.log(arg.length);
//     return arg;
// }
// // console.log(loggingIdentity(3)) // 오류
// // console.log(loggingIdentity("ㅁㄴㅇㅁㄴㅇ"))          // OK
// // console.log(loggingIdentity([1,2,3,4,]))             // OK
// console.log(loggingIdentity({length: 10, value: 3}));   // OK
// function getProperty<T, K extends keyof T>(obj: T, key: K) {
//     return obj[key];
// }
// let x = {a:1, b:2, c:3, d:4};
// getProperty(x, "a");
// getProperty(x, "d");
// function create<T>(c: {new(): T; }): T{
//     return new c();
// }
function calcAvgHeight(data) {
    var LEN = Object.keys(data).length;
    if (data === undefined || LEN === 0) {
        return null;
    }
    var sum = 0;
    Object.keys(data).forEach(function (key) {
        console.log(key, data[key]);
        var height = data[key].height;
        console.log(height);
        sum += height;
    });
    return sum / LEN;
}
var avgHeight = calcAvgHeight({});
console.log(avgHeight);
