﻿using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;

namespace Effekseer.Data.Value
{
	public class PathForCurve : Path
	{
		internal PathForCurve(string filter, bool isRelativeSaved, string abspath = "")
			: base(filter, isRelativeSaved, abspath)
		{
		}
	}
}
