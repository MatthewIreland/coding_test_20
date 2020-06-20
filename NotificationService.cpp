//
// Created by matthew on 20/06/2020.
//

#include "NotificationService.h"

void NotificationService::subscribeToNotification(std::function<void(int)> f)
{
    subscribers_.push_back(std::move(f));
}

void NotificationService::generateNotification(int i)
{
    for (auto& subscriber: subscribers_)
    {
        subscriber(i);
    }
}
