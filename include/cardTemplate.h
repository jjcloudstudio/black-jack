const char cardEdge[] = "+-----------+ ";
const char blankRow[] = "|           | ";

const char* cardBack[8] {
    cardEdge,
    R"(| \ /\ /\ / | )",
    R"(| / \/ \/ \ | )",
    R"(| \ /\ /\ / | )",
    R"(| / \/ \/ \ | )",
    R"(| \ /\ /\ / | )",
    R"(| / \/ \/ \ | )",
    cardEdge
};

const char* aceCard[8] {
    cardEdge,
    "|A          | ",
    blankRow,
    "|    Ace    | ",
    blankRow,
    blankRow,
    "|          A| ",
    cardEdge
};

const char* twoCard[8] {
    cardEdge,
    "|2          | ",
    blankRow,
    "|    Two    | ",
    blankRow,
    blankRow,
    "|          2| ",
    cardEdge
};

const char* threeCard[8] {
    cardEdge,
    "|3          | ",
    blankRow,
    "|   Three   | ",
    blankRow,
    blankRow,
    "|          3| ",
    cardEdge
};

const char* fourCard[8] {
    cardEdge,
    "|4          | ",
    blankRow,
    "|   Four    | ",
    blankRow,
    blankRow,
    "|          4| ",
    cardEdge
};

const char* fiveCard[8] {
    cardEdge,
    "|5          | ",
    blankRow,
    "|   Five    | ",
    blankRow,
    blankRow,
    "|          5| ",
    cardEdge
};

const char* sixCard[8] {
    cardEdge,
    "|6          | ",
    blankRow,
    "|    Six    | ",
    blankRow,
    blankRow,
    "|          6| ",
    cardEdge
};

const char* sevenCard[8] {
    cardEdge,
    "|7          | ",
    blankRow,
    "|   Seven   | ",
    blankRow,
    blankRow,
    "|          7| ",
    cardEdge
};

const char* eightCard[8] {
    cardEdge,
    "|8          | ",
    blankRow,
    "|   Eight   | ",
    blankRow,
    blankRow,
    "|          8| ",
    cardEdge
};

const char* nineCard[8] {
    cardEdge,
    "|9          | ",
    blankRow,
    "|   Nine    | ",
    blankRow,
    blankRow,
    "|          9| ",
    cardEdge
};

const char* tenCard[8] {
    cardEdge,
    "|10         | ",
    blankRow,
    "|    Ten    | ",
    blankRow,
    blankRow,
    "|         10| ",
    cardEdge
};

const char* jackCard[8] {
    cardEdge,
    "|J          | ",
    blankRow,
    "|   Jack    | ",
    blankRow,
    blankRow,
    "|          J| ",
    cardEdge
};

const char* queenCard[8] {
    cardEdge,
    "|Q          | ",
    blankRow,
    "|   Queen   | ",
    blankRow,
    blankRow,
    "|          Q| ",
    cardEdge
};

const char* kingCard[8] {
    cardEdge,
    "|K          | ",
    blankRow,
    "|   King    | ",
    blankRow,
    blankRow,
    "|          K| ",
    cardEdge
};

const char** cardTemplate[14] {
    cardBack,
    aceCard,
    twoCard,
    threeCard,
    fourCard,
    fiveCard,
    sixCard,
    sevenCard,
    eightCard,
    nineCard,
    tenCard,
    jackCard,
    queenCard,
    kingCard
};
