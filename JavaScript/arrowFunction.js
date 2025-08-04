const obj = {
    n: "John",
    age: 30,
    arrowfunction: () => {
        console.log(this.n, this.age);
    },
    normalfunction: function () {
        console.log(this.n, this.age);
    },
};

//this in arrowfunction refers to the outer(lexical) scope, window in browser and global in node
//in normalfunction this refers to the object on which it is called here it is obj
// obj.arrowfunction();
// obj.normalfunction();

// function normal(name) {
//     this.name = name;
//     console.log(this);
// }
// new normal("John");

function Person(name) {
    this.name = name;
    setTimeout(
        function () {
            console.log(`Hello, my name is ${this.name}`);
        }.bind(this),
        1000
    );
}
new Person("Bob");
