## A05

- Name: Yoseph Helal
- Date: 29 Nov 2021
- Class: 2143 OOP

## Definitions

#### Abstraction

> Abtraction is all about how we design our class and the main goal really out of abstraction is to just design our code in a way where the end user has a simple interface that's easy to use and that's all they have to worry about. All the internal workings and complicated parts of a class are tucked inside the class and the user doesn't have to worry about understanding them. Similar to a coffee maker. You know how to use it and make use of the simplicity it provides without needing to worry about what goes on inside to make your coffee.
>
><img src="https://cdn.journaldev.com/wp-content/uploads/2019/09/process-abstraction-1024x737.png" width=500>

#### Attributes / Properties

> Attributes and properties are basically the same thing. These are considered to be the data members in a class that make it unique and separate from other classes. For example, some attributes or properties of a person would be their name, age, and height. Speaking and eating can be considered behaviors or methods of the class.
>
><img src="https://www.oreilly.com/library/view/hands-on-object-oriented-programming/9781789617726/assets/25c48d63-51cf-4aac-b1dc-1a449d41f7b1.png" width=500>

#### Class

> A class is really just a "blue print" for creating objects. For example, I have a class car that represents a car and the objects of that class are numerous types of cars.
>
><img src="https://ds055uzetaobb.cloudfront.net/brioche/uploads/pJZt3mh3Ht-prettycars.png?width=2400" width=500>

#### Class Variable

> A class variable is just any variable that is declared within a class. It can be a local, static, or instance variable
>
><img src="https://media.geeksforgeeks.org/wp-content/cdn-uploads/20191113121956/TypesofVariableInC.png" width=500>

#### Composition

> Composition is usually seen being compared against inheritance. With Composition, instead of inheriting from a parent class, you create an instance of a class inside and other class and that's how you use your class. You compose an object of one class in another class, hence composition.
>

#### Constructor

> A constructor is a function or a method in a class with the same name as the class and it's the method that runs automatically as soon as an instance of a class or an object is created. It can be overloaded using different parameter lists.

#### Encapsulation

> Encapsulation is a concept in OOP that is very closely related to abstraction, but deals more with implementation rather than design. Encapsulation is all about putting your variables in their appropriate classess and packaging them with the methods that act on them. It's all about having a class with its variables and its methods that act on those variables all packaged together similar to a "capsule."
>
><img src="https://miro.medium.com/max/778/1*axAnHOiQgWtblRlyhFBCbA.jpeg" width=500>


#### Friends

> Friends is a little trick that OOP programmers will use and all it does is basically allow a function or a whole class, depends on what you make a friend, to access the private and protected data members of any given class as if that function was a member of function of the class whose privates are going to be accessed. You can also make a whole class a friend and allow it to access the privates and protecteds of any given class, just declare it as a friend in the body of the class whose privates and protecteds you want to access.

#### Inheritance

> Inheritance is a major concept in OOP that deals with having one class, a child class, inherit public and protected members from another class, the parent class, and using those variables as its own. Inheritance is mostly used when two objects have an IS A relationship as shown in the diagram below. Inheritance also makes your code easier to read since it saves some lines of code, less room for mistakes, and more organized.
>
><img src="https://miro.medium.com/max/875/1*CaTNbDiboMzEXuBB2AaDjg.png" width=500>

#### Instance Variable

> A type of class variable. Simply a regular variable in a class. Called an instance variable because every instance of a class or object has a separate copy.
>
><img src="https://media.geeksforgeeks.org/wp-content/cdn-uploads/20191113121956/TypesofVariableInC.png" width=500>


#### Member Variable

> A type of class variable. Any variable that belongs to a class is called a member variable.
>
><img src="https://media.geeksforgeeks.org/wp-content/cdn-uploads/20191113121956/TypesofVariableInC.png" width=500>


#### Method

> Any function in a class is considered a method of that class.
>
><img src="https://upload.wikimedia.org/wikipedia/commons/thumb/9/98/CPT-OOP-objects_and_classes_-_attmeth.svg/1000px-CPT-OOP-objects_and_classes_-_attmeth.svg.png" width=500>

#### Object

> An object is considered to be an instance of a class.
>
><img src="https://lh3.googleusercontent.com/proxy/Wc-oejJ7EWoWE3SU0Ox8kV8VVSYUM7S9ZRUJx35AXknoAlBviXSEoXq339d3eoY4zvQlptH5pQwxzFeyTCVrQ4hnRN9sk0xFpRE" width=500>


#### Overloading

> Allows you to write more than one function with the same name in the same scope, as long as they have different parameter lists.
>
><img src="https://simplesnippets.tech/wp-content/uploads/2018/03/function-overloading-in-cpp-1280x720.png" width=500>

#### Polymorphism

> Polymorphism at its root means "many forms". Polymorphism describes the idea that you can use a lot of different classess and they can all have the same functions, but each class has its own different implementation suited to its needs for each function. In a way, it gives you many ways to do one thing.
>
><img src="https://media.geeksforgeeks.org/wp-content/uploads/20190705113259/Polymorphism-1.jpg" width=500>
>><img src="https://javatutorial.net/wp-content/uploads/2017/10/java-polymorphism-featured-image-1280x720.png" width=500>

#### Public / Private / Protected

> Different access specifiers used in classes to protect your class variables.
> Private: Only Friends and the class itself can access those variables and methods
> Protected: Only Friends, derived classes, and the class itself can access those variables and methods.
> Public: Everybody and the class itself can access those variables. Absolutely no protection.
>
><img src="https://beeimg.com/images/a54379718832.png" width=500>
