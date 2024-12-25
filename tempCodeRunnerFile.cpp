
            registerUser();
            break;
        case 2:
            if (loginUser()) {
                system("cls"); // Clear the console
                mainPage();
            } else 