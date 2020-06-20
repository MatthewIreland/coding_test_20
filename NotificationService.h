//
// Created by matthew on 20/06/2020.
//

#ifndef CODING_TEST_20_NOTIFICATIONSERVICE_H
#define CODING_TEST_20_NOTIFICATIONSERVICE_H

#include <list>
#include <functional>

class NotificationService
{
public:
    void subscribeToNotification(std::function<void(int)> f);
    void generateNotification(int i);

private:
    std::list<std::function<void(int)>> subscribers_;
};


#endif //CODING_TEST_20_NOTIFICATIONSERVICE_H
