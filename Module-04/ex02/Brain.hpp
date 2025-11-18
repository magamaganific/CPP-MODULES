#ifndef BRAIN_HPP
# define BRAIN_HPP
# include <iostream>

class Brain{
public:
	Brain(void);
	Brain(const Brain &old);
	Brain &operator=(const Brain &old);
	~Brain(void);

	std::string getIdeas(void) const;
protected:
	std::string _ideas[100];
};
#endif