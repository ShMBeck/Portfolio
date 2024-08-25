**Shane Beck, Student at SNHU for a Bachelors in Computer Science.**
**CS 305 Artemis Financial Project**

1. Briefly summarize your client, Artemis Financial, and its software requirements. Who was the client? What issue did the company want you to address?

Artemis Financial is a consulting company that specializes in creating personalized financial plans for its clients, including savings, retirement, investments, and insurance. The company sought to modernize its operations by integrating advanced software security measures to protect sensitive financial data transmitted through its public web interface. Specifically, Artemis Financial required a secure communication mechanism, including the addition of a file verification step via checksum, to ensure the integrity and security of data during transmission.
2. What did you do well when you found your client’s software security vulnerabilities? Why is it important to code securely? What value does software security add to a company’s overall well-being?

I conducted a thorough analysis of the existing software to identify potential security vulnerabilities, focusing on the absence of encryption and the need for data integrity checks. By implementing SSL/TLS encryption and a checksum verification mechanism, I addressed these vulnerabilities effectively. Secure coding is crucial because it minimizes the risk of data breaches, protects client information, and maintains the integrity of the software. Software security significantly enhances a company's reputation, customer trust, and compliance with industry regulations, ultimately contributing to the company’s overall success and longevity.
3. Which part of the vulnerability assessment was challenging or helpful to you?

The most challenging part of the vulnerability assessment was ensuring that the SSL/TLS configuration was correctly implemented, especially when dealing with self-signed certificates. Understanding the intricacies of certificate management and trust issues was crucial. On the other hand, using tools like the OWASP Dependency-Check was extremely helpful in identifying vulnerabilities in third-party libraries, which are often overlooked but can be a significant security risk.
4. How did you increase layers of security? In the future, what would you use to assess vulnerabilities and decide which mitigation techniques to use?

I increased layers of security by enabling HTTPS for secure communication, implementing checksum verification for data integrity, and using static analysis tools to identify and address potential vulnerabilities in the codebase. In the future, I would continue to use a combination of automated tools, such as OWASP Dependency-Check, and manual code reviews to assess vulnerabilities. Additionally, adopting a defense-in-depth approach, where multiple security controls are layered, would be key to mitigating risks effectively.
5. How did you make certain the code and software application were functional and secure? After refactoring the code, how did you check to see whether you introduced new vulnerabilities?

I ensured the functionality and security of the code by running comprehensive unit tests, including testing the checksum endpoint for accuracy and ensuring the application ran smoothly over HTTPS without any security warnings. After refactoring the code, I used the OWASP Dependency-Check tool to perform static analysis and identify any new vulnerabilities introduced during the changes. This combination of testing and static analysis provided confidence that the application remained secure and functional.
6. What resources, tools, or coding practices did you use that might be helpful in future assignments or tasks?

The resources and tools that were particularly helpful include:

    Java Keytool: For generating and managing SSL certificates.
    Spring Boot: For building secure web applications with integrated support for SSL/TLS.
    OWASP Dependency-Check: For identifying vulnerabilities in third-party dependencies.
    Best Practices: Adopting secure coding practices, such as input validation, proper error handling, and the principle of least privilege, which are essential for maintaining secure applications.

7. Employers sometimes ask for examples of work that you have successfully completed to show your skills, knowledge, and experience. What might you show future employers from this assignment?

From this assignment, I would showcase my ability to identify and mitigate software security vulnerabilities effectively. I would highlight my work on implementing SSL/TLS encryption, setting up a secure checksum verification system, and using industry-standard tools like OWASP Dependency-Check to maintain the security and integrity of the software. These examples demonstrate my proficiency in secure coding practices, problem-solving, and my commitment to delivering secure and reliable software solutions.
**Software Design Document for The Gaming Room:**
**Project Developed during April of 2023.**

Summary:
    Draw It or Lose It, the game where teams will compete to guess what is being drawn, where they will use rendered stock drawings as clues. It was consist of four rounds of one minute each, with the drawing clues being fully complete at the 30-second mark. Each team will have a chance to offer a guess provided the first team fails to guess. Our client, The Gaming Room, requires our help to setup the environment for a web-based version of the game which is currently only available as an android application.

**What did you do particularly well in developing this documentation?**
    I analyzed the clients requirements thoroughly and recommended software that I found would be best for their needs. I believe that this is one aspect that I did very well.

**What about the process of working through a design document did you find helpful when developing the code?**
    Having the details of the document spelled out for me in a manner of speaking allowed me to easily decide what exactly I needed to code and how much more easily.

**If you could choose one part of your work on these documents to revise, what would you pick? How would you improve it?**
    I would work more on the design constraints, going more in-depth and in general just improving them to the clients specifications.

**How did you interpret the user’s needs and implement them into your software design? Why is it so important to consider the user’s needs when designing?**
    I made sure to implement their needs through ensuring the software would be easy for the user to use. If the user's needs are not considered then the design of the software is destined to fail, no user, no software.
**
How did you approach designing software? What techniques or strategies would you use in the future to analyze and design a similar software application?**
    I approached it through a thought-out part by part method, constructing one piece at a time and slowly building on top of it. In the future I believe it would be best to add more OOP elements into my design.

**Contact List:**
**Project Developed during february of 2023.**

**Summarize the project and what problem it was solving.:**
    the project is that of a contact list, in essence a contact list is a list that works through "contacting" or linking multiple objects together through properties of each object. You could view it similarly to a family tree in the sense that a mother is linked to their son, and the son is linked to his wife and children, etc.

**What did you do particularly well?:**
    I am content with how well I did in making use of classes to reuse code rather than constantly repeating myself.

**Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?:**
    I could work on cleaning it up more and organizing it more than it already is, doing so would allow easier usage of the code and future modification, both by myself and others.

**Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?:**
    In terms of difficulty the most difficult was just the methods I had to implement to properly get the frequency of each product, it wasn't particularly hard, but it did take me longer than the rest to program.

**What skills from this project will be particularly transferable to other projects or course work?:**
    The most transferable skill is my further development of my usage of classes, I am quite fond of classes but didn't have much experience with them in c++ until now.

**How did you make this program maintainable, readable, and adaptable?:**
    I made sure to include a bunch of comments throughout the code to allow for others to understand it, as well as myself, and change it easier than it otherwise would be. I also made sure that each class would be easy to change and adapt by implementing as many methods as I can rather than rewriting code repeatedly in multiple place.

**Project Developed April of 2024**

**CS-250-R4763 Software Development Lifecycle 24EW4**

How do I interpret user needs and implement them into a program? How does creating “user stories” help with this?**

Interpreting user needs involves understanding the requirements and expectations of the end-users and translating them into actionable tasks for development. User stories serve as a valuable tool in this process by providing a structured format for capturing user requirements from their perspective. By creating user stories, we can articulate user needs in a clear and concise manner, making it easier to prioritize and implement them into the program effectively.
    
**How do I approach developing programs? What agile processes do I hope to incorporate into my future development work?**

When approaching program development, I prioritize collaboration, adaptability, and continuous improvement. Agile processes, such as Scrum, have been instrumental in facilitating these principles by promoting iterative development, frequent feedback, and flexibility in responding to change. In my future development work, I aim to incorporate agile practices such as sprint planning, daily stand-up meetings, and regular retrospectives to enhance productivity, transparency, and stakeholder satisfaction.
    
**What does it mean to be a good team member in software development?**

Being a good team member in software development entails effective communication, collaboration, and a commitment to shared goals. It involves actively listening to teammates, respecting diverse perspectives, and contributing constructively to discussions and decision-making processes.

**CS-255-R4796 System Analysis and Design 24EW4**

**Briefly summarize the DriverPass project. Who was the client? What type of system did they want you to design?**
Client: DriverPass
Objective: To design a system that enhances the preparation for driving tests through online and on-the-road training. DriverPass aimed to fill a market gap by providing a robust platform that supports scheduling lessons, managing user data, and integrating updates from the DMV.

**What did you do particularly well?**
I excelled in integrating user feedback mechanisms into the system design, ensuring that DriverPass could continually adapt to user needs and preferences, therefore improving customer satisfaction and system usability.

**If you could choose one part of your work on these documents to revise, what would you pick? How would you improve it?**
I think if I were to improve anything I would like to improve my diagrams; My digrams could have been more detailed and addressed more use cases, etc.

**How did you interpret the user’s needs and implement them into your system design? Why is it so important to consider the user’s needs when designing?**
User needs were interpreted through engaging with client interviews and user scenarios, which helped in designing a system that is intuitive and meets practical requirements. Considering user needs is crucial because it ensures the system will be actively used and valued by its intended audience, thereby fulfilling its purpose.

**How do you approach designing software? What techniques or strategies would you use in the future to analyze and design a system?**
My approach includes thorough requirement analysis, iterative design with user feedback, and using modeling tools like UML diagrams for clarity in system architecture. In future projects, I plan to incorporate more prototyping and agile methodologies to allow for flexible and adaptive system design, ensuring that user feedback and changing requirements can be integrated seamlessly into the development process.

