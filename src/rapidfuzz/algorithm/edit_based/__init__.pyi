from typing import Tuple, List

class Editops:
    @classmethod
    def from_opcodes(cls, other: Opcodes) -> Editops: ...

    def as_opcodes(self) -> Opcodes: ...

    def as_list(self) -> List[Tuple[str, int, int]]: ...

    def __eq__(self, other: Editops) -> bool: ...

    def __len__(self) -> int: ...

    def __getitem__(self, index: int) -> Tuple[str, int, int]:

    def __repr__(self) -> str: ...

class Opcodes:
    @classmethod
    def from_editops(cls, other: Editops) -> Opcodes: ...

    def as_editops(self) -> Editops: ...

    def as_list(self) -> List[Tuple[str, int, int, int, int]]: ...

    def __eq__(self, other: Editops) -> bool: ...

    def __len__(self) -> int: ...

    def __getitem__(self, index: int) -> Tuple[str, int, int, int, int]:

    def __repr__(self) -> str: ...
