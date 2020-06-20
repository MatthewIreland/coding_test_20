# Coding Test 2020

Thank you for your interest in our summer internship!
To help us decide on the candidate who will be the be best fit for the position, we have three
exercises that we hope you'll find challenging but enjoyable.

Please send your solutions to matthew@ireland.cx in some sensible format.
When sending your solution please indicate how much past C++ experience you have
(especially if you have learnt C++ especially for this task) so that we can assess your
submission in that context.
(For example, if you have only just learnt C++ but completed the exercises really well, that
will be looked on favourably.)

As a rough guide, we'd expect the first exercise to take around an hour, the second exercise
to take two hours, and the final exercise to take roughly 30 minutes.

Very best of luck!

## Task 1 (unit testing)

`NotificationService` allows users to subscribe to notifications, and will notify subscribed
users when the `generateNotification` method is called.

Use the [GoogleTest](https://github.com/google/googletest) unit testing framework to write
unit tests for the NotificationService class.

Although the class was not written with any bugs intentionally inserted, report any bugs
that you find and propose fixes for these bugs.


## Task 2 (unit testing + end-to-end testing + interop testing)

The Discrete Fourier Transform is an invertible linear operator that can be applied to an
array of complex numbers.
This repository contains two implementations of the `IFourierTransform` interface:
`DiscreteFourierTransform` and `FastFourierTransform`. Each computes the Discrete Fourier
Transform of a vector of complex numbers, but uses a different algorithm to do so.

Write tests for `DiscreteFourierTransform` and `FastFourierTransform`. Your solution should 
include unit tests, but should not be limited to only including unit tests.

Again, although the class was not written with any bugs intentionally inserted, report any bugs
that you find and propose fixes for these bugs.


## Task 3

Suggest improvements that could be made to the code in any of the classes in this repository.

