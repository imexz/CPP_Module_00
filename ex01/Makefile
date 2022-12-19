NAME = minitel
CC = c++
CPPFLAGS = -Wall -Wextra -Werror -std=c++98 -pedantic
RM = rm -f
SOURCES =	./Contact.cpp \
			./main.cpp \
			./PhoneBook.cpp \
			./Manager.cpp \
			./Printer.cpp \
			./Scanner.cpp \
			./StaticUtils.cpp

#build everything
all: $(NAME)

#creates programm
$(NAME): $(SOURCES)
	$(CC) $(CPPFLAGS) $(SOURCES) -o $(NAME)

#removes executable
clean:
	$(RM) $(NAME)

#removes executable and rebuild it
re: clean all
