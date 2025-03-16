#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>


void accounting_questions (int * cur_pos, int ofst, int all_qa, bool resolved []) // расчет и проверка на повтор нового сектора  
{
    (*cur_pos) += ofst;

        if ( (*cur_pos) > all_qa)
            (*cur_pos) = ((*cur_pos) - 1) % all_qa ;


        while (resolved [(*cur_pos)] == 1 )
        {
            std::cout <<"\nВопрос под номером "<<(*cur_pos) + 1<<" уже разыгрывался в игре.\nПереходим к следующему\n";
            (*cur_pos) += 1;

            if ( (*cur_pos) > all_qa)
                (*cur_pos) = ((*cur_pos) - 1) % all_qa ;
        }

        resolved [ (*cur_pos)] = 1;
}

void show_question (std::string questions_files_path, std::ifstream &question, char num_in_char [], int curr_pos) // считать и вывести на экран вопрос
{
        std::string buffer_for_question;
        
        question.open (questions_files_path  + num_in_char + ".txt");
        
        getline (question, buffer_for_question);
        std::cout << "Вопрос №"<<curr_pos<<"\n";
        std::cout << buffer_for_question << std::endl ;
        question.close();
}

bool get_and_check_answers (std::ifstream &answer, std::string answers_file_path, char num_in_char []) // считывание ответа и проверка правильного
{
        answer.open (answers_file_path  + num_in_char + ".txt");
            
        std::string buffer_for_answer;
        getline(answer, buffer_for_answer);  

        answer.close();

        std::string answer_the_question;
        getline (std::cin, answer_the_question) ;

        

        if (answer_the_question == buffer_for_answer)
        {
            std::cout << "Правильно! Балл достается команде знатоков\n";
            return true;
        }
            
        else
        {
            std::cout << "Неверно! Балл достается команде зрителей\n";
            std::cout << "Правильный ответ: " << buffer_for_answer <<"\n";
            return false;
        }
            
}

int main () 
{
    
    setlocale (LC_ALL, "Rus");
    std::ifstream question;
    std::ifstream answer;

    std::string questions_file_path = "D:\\projects\\practic_19.5\\Questions\\q";
    std::string answers_file_path = "D:\\projects\\practic_19.5\\Answers\\a";

    int players_scores = 0;             // очки команд
    int audience_scores = 0;
    int all_questions = 12;             // кол-во всех вопросов
    bool resolved [13] = {0};           // массив для обозначения уже сыгранных вопросов 
    int ofset;                          // значение смещения относительно сектора
    int current_position = 0;           // текущий сектор 
    int * p_current_position = &current_position;
    

    std::cout << "Добро пожаловать на игру Что? Где? Когда?\n";

    while (players_scores != 6 && audience_scores != 6)
    {
        std::cout << "Крутите волчок\n";
        
        std::cin >> ofset;

        char num_in_char [3];  // массив для перевода номера сектора в char для присоединения к пути к  соответ-им файлам с вопросом/ответом
        
        accounting_questions( p_current_position, ofset, all_questions, resolved );
        
        itoa (current_position + 1, num_in_char, 10);
        
        show_question (questions_file_path, question, num_in_char, current_position + 1);
        
        std::cin.ignore();


        if (get_and_check_answers (answer, answers_file_path, num_in_char))
            players_scores += 1;
        
        else
            audience_scores += 1;
    
        std::cout << "\n\nСчет на текущий момент: \nЗнатоки - "<<players_scores<<"\nЗрители - "<<audience_scores<<"\n\n";
        
    }
   
    if (players_scores > audience_scores)
        std::cout << "\n\n Победили знатоки\n";

    else   
        std::cout << "\n\n Победили зрители\n";

    
    return 0;

}




