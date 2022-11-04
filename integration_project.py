# BILAL DOGUTAS
'''
**FUNCTIONAL CALCULATOR**
-This calculator can do calculation with 7 numerical operators.
-Also can do the string calculation such as concatenation and multiplicate the words.
***New Features**
-Frog calculation that print as many as frog that you want
-Student average calculator which can calculate averages of three students
-Counting even and odd numbers
'''

print("******FUNCTIONAL CALCULATOR******")  # headline
print("\n1-Numerical Calculation")
print("2-String Calculation")
print("3-Frog Calculator")
print("4-Student Average Calculator")
print("5-Even and Odd Number Accumulator")
the_selection = int(input(
    "\nWhich calculation do you want to do?\nSelect one=>"))
# In this part code gets the style of the calculation

if the_selection == 1:  # numerical calculation part
    print("\nNumerical Calculation")
    num1 = float(input("\nEnter the first number: "))
    num2 = float(input("Enter the second number: "))
    print(
        "\n1-Addition\n2-Substraction\n3-Multiplication\n4-Division\n"
        "5-Exponent\n6-Remainder\n7-Floor Division")
    # In this part of code I print the options of the calculation.
    selected_calculation1 = int(input(
        "\nWhat calculation do you want to do?\nSelect one=> "))
    # In this part I get the selection of the type of calculation.

    if selected_calculation1 == 1:
        print("Answer is:", format(num1 + num2, ".2f"), sep='')  # addition
    elif selected_calculation1 == 2:
        print("Answer is:", format(num1 - num2, ".2f"), sep='')  # substraction
    elif selected_calculation1 == 3:
        print("Answer is:", format(num1 * num2, ".2f"), sep='')  # multiplication
    elif selected_calculation1 == 4:
        print("Answer is:", format(num1 / num2, ".2f"), sep='')  # division
    elif selected_calculation1 == 5:
        print("Answer is:", format(num1 ** num2, ".2f"), end='')  # exponent
    elif selected_calculation1 == 6:
        print("Answer is:", format(num1 % num2, ".2f"), end='')  # remainder
    elif selected_calculation1 == 7:
        print("Answer is:", format(num1 // num2, ".2f"), end='')  # floor division
    else:
        print("!!!You typed a wrong number!!!")  # The input must be 1 to 7.

elif the_selection == 2:  # string calculation part
    print("\nString calculation")
    print("\n1-Concatenation\n2-Multiplication")
    selected_calculation2 = int(input("What calculation do you want to do?\nSelect one=> "))

    if selected_calculation2 == 1:
        variable1 = input("\nEnter the first variable(Word or a number): ")
        variable2 = input("Enter the second variable(Word or a number: ")
        print(variable1 + variable2)  # concatenation of two pictures
    elif selected_calculation2 == 2:
        variable1 = input("\nEnter the first variable(A word): ")
        variable2 = int(input("Enter the second variable(A number): "))
        print(variable1 * variable2)  # multiplication word and a number
    else:
        print("!!!You have to choose 1 or 2!!!")
        # Input must be 1 or 2 so that's a kind of an error for my calculator.
elif the_selection == 3 and (the_selection != 4):  # frog calculator part
    def frog(dots):
        print(dots * ("\n   @..@\n  (----)\n ( >___< )\n ^^ == ^^"))
        # Printing the Frog dots as many as number is


    def main():  # Asks user about how many frogs do you want to print
        number = int(input("How many frogs? "))
        frog(number)  # Calls the frog()


    main()
    # ****Calls the main****
elif the_selection == 4 or (not (3 and 2)):  # student average calculator part

    student_names = []  # opening a empty list for variables
    averages = []  # opening a empty list for variables
    print("You can only enter three students!!")
    for student in range(3):  # getting the names of the students 3 times
        name = input("Name of the Student: ")
        student_names.append(name)  # adding the name of the students in first list

        for grades in range(1):  # getting the grades of the students
            grade1 = int(input("First grade of the student: "))
            grade2 = int(input("Second grade of the student: "))
            grade3 = int(input("Third grade of the student: "))
            answer = ((grade1 + grade2 + grade3) / 3)
            # calculating the grade average that entered
            averages.append(answer)
            # adding the averages of the students in second list

            if (grade1 or grade2 or grade3) < 0 or (grade1 or grade2 or grade3) > 100:
                print("Please enter a valid grade!!!")  # grades must between 0 and 100

    print("\nName:", student_names[0])  # picking the names from the list ([0]=1. [1]=2.)
    print("Average:", format(averages[0], ".2f"))
    print("Name:", student_names[1])
    print("Average", format(averages[1], ".2f"))
    print("Name:", student_names[2])
    print("Average:", format(averages[2], ".2f"))
    # printing the student names and grades in two decimal places
elif the_selection == 5:
    even_count = 0
    odd_count = 0
    running = True
    print("**Stop entering numbers with entering '-1'.**")
    while (running):
        number = int(input("Enter a number: "))
        if number % 2 == 0:  # if remainder is 0 it is even
            even_count += 1  # even accumulator
        elif number == -1:
            running = False  # when entered '-1' program stops
        else:
            odd_count += 1  # odd accumulator
    print("Total of even numbers:", even_count, "\nTotal of odd numbers:", odd_count)
else:
    print("!!!You have to choose 1, 2, 3, 4 or 5!!!")  # Input must be 1, 2, 3, 4 or 5.
