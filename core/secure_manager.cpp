#include "secure_manager.h"


Secure_manager::Secure_manager()
{

}

int Secure_manager::check_capability(Secure_manager::secure_level expected_level)
{
    return this->level > expected_level;
}
