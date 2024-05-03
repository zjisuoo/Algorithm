from mymodule import myfunc as better_named_func
from datetime import datetime, timezone # two imports on the same line
from unittest.mock import patch # single import

import pytest # third party library

from core.models import( # multiline import
    Exam,
    Exercise,
    Solution,
)