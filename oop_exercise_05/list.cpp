#include "pentagon.cpp"
#include <memory>


class elem
{
private:
    std::shared_ptr <elem> next; 
    std::shared_ptr <elem> prev;
    std::shared_ptr <pentagon> fig;
  
public:
    elem()
    {
        next = NULL;
        prev = NULL;
        fig = NULL;
    }
    elem(std::shared_ptr<pentagon> &fig) : fig(fig), next(NULL), prev(NULL){}
    
    std::shared_ptr<elem> get_next()
    {
        return next;
    }
    std::shared_ptr<elem> get_prev()
    {
        return prev;
    }
    std::shared_ptr<pentagon> get_fig()
    {
            return fig;
    }
    void set_prev(std::shared_ptr<elem> prev)
    {
        this->prev = prev;
    }
    void set_next(std::shared_ptr<elem> next)
    {
        this->next = next;
    }
    ~elem()
    {

    }



};


class list
{
private:
    std::shared_ptr <elem> head;
    std::shared_ptr <elem> last;
    int size;
public:
    list()
    {
        head = NULL;
        last = NULL;
        size = 0;
    }
    ~list()
    {
    }
    void insert_last(std::shared_ptr <pentagon> fig)
    {
        if (head == NULL)
        {
            
            std::shared_ptr <elem> curr(new elem(fig));
            head = curr;
            last = curr;
        }
        else 
        {
            std::shared_ptr <elem> curr(new elem(fig));
            if (size == 1) 
            {
                curr->set_prev(head);
                head->set_next(curr);
                last = curr;
            }
            else
            {
                curr->set_prev(last);
                last->set_next(curr);
                last = curr;
            }
        }
        size++;
    }
    void output()
    {
        std::shared_ptr <elem> curr = head;
        while (curr != NULL)
        {
            curr->get_fig()->output();
            curr = curr->get_next();
        }
    }
    void insert(int pos, std::shared_ptr<pentagon> fig)
    {
        std::shared_ptr <elem> curr = head;
        std::shared_ptr <elem> new_elem ;
        std::shared_ptr <elem> helper;
        int counter = 1;

        while (counter != pos)
        {
            curr = curr->get_next();
            counter++;
        }
        
        helper = curr->get_fig();
        new_elem = helper;
        curr = curr->get_prev();


       

            
    }
};
