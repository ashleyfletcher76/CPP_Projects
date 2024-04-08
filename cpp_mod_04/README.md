This C++ system implements a simulation of Materias and Characters, demonstrating subtype polymorphism, abstract classes, and interfaces. The system allows Materias to be created, cloned, equipped to characters, and used against other characters. There are two types of Materias (Ice and Cure) and a character can hold up to four Materias at a time.

Class AMateria:
A pure abstract class (interface) representing a generic Materia. It defines the common interface for all concrete Materias.

- Methods:
  - clone(): Creates and returns a new instance of the same type of Materia.
  - use(ICharacter& target): Defines how the Materia interacts with a character (the effect varies by Materia type).
  - getType(): Returns the Materia type as a string.

- Member Variables:
  - std::string type: The type of the Materia (e.g., "ice" or "cure").

Class Ice (inherits from AMateria):
Represents an Ice Materia. Implements the clone and use methods.

- clone(): Returns a new instance of Ice.
- use(ICharacter& target): Displays the effect of using the Ice Materia on the target character.

Class Cure (inherits from AMateria):
Represents a Cure Materia. Implements the clone and use methods.

- clone(): Returns a new instance of Cure.
- use(ICharacter& target): Displays the effect of using the Cure Materia on the target character.


Interface ICharacter:
Defines the interface for a character in the system.

- Methods:
  - getName(): Returns the name of the character.
  - equip(AMateria* m): Equips a Materia to the character.
  - unequip(int idx): Unequips a Materia from the character without deleting it.
  - use(int idx, ICharacter& target): Uses the equipped Materia at the specified index on the target character.

Class Character (implements ICharacter):
Represents a character in the system with an inventory for Materias.

- Constructor: Accepts a name and initializes the character.
- Destructor: Ensures all equipped Materias are properly deleted.
- Copy Constructor and Assignment Operator: Perform deep copies of the inventory.


Interface IMateriaSource:
Defines the interface for a Materia source, which can learn and create Materias.

- Methods:
  - learnMateria(AMateria*): Takes a Materia, clones it, and stores the clone for later creation.
  - createMateria(std::string const & type): Creates and returns a new Materia of the specified type.

Class MateriaSource (implements IMateriaSource):
Represents a source of Materias, capable of learning and creating specific Materias.

- Member Variables:
  - A storage mechanism for learned Materias (up to 4).


