/*
 * $Id: LogoffAction.java 471754 2006-11-06 14:55:09Z husted $
 *
 * Licensed to the Apache Software Foundation (ASF) under one
 * or more contributor license agreements.  See the NOTICE file
 * distributed with this work for additional information
 * regarding copyright ownership.  The ASF licenses this file
 * to you under the Apache License, Version 2.0 (the
 * "License"); you may not use this file except in compliance
 * with the License.  You may obtain a copy of the License at
 *
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing,
 * software distributed under the License is distributed on an
 * "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
 * KIND, either express or implied.  See the License for the
 * specific language governing permissions and limitations
 * under the License.
 */


package org.apache.struts.webapp.example2;


import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.servlet.http.HttpSession;
import org.apache.commons.logging.Log;
import org.apache.commons.logging.LogFactory;
import org.apache.struts.action.Action;
import org.apache.struts.action.ActionForm;
import org.apache.struts.action.ActionForward;
import org.apache.struts.action.ActionMapping;


/**
 * Implementation of <strong>Action</strong> that processes a
 * user logoff.
 *
 * @author Craig R. McClanahan
 * @version $Rev: 471754 $ $Date: 2006-11-06 08:55:09 -0600 (Mon, 06 Nov 2006) $
 */

public final class LogoffAction extends Action {


    // ----------------------------------------------------- Instance Variables


    /**
     * The <code>Log</code> instance for this application.
     */
    private Log log =
        LogFactory.getLog("org.apache.struts.webapp.Example");


    // --------------------------------------------------------- Public Methods


    /**
     * Process the specified HTTP request, and create the corresponding HTTP
     * response (or forward to another web component that will create it).
     * Return an <code>ActionForward</code> instance describing where and how
     * control should be forwarded, or <code>null</code> if the response has
     * already been completed.
     *
     * @param mapping The ActionMapping used to select this instance
     * @param form The optional ActionForm bean for this request (if any)
     * @param request The HTTP request we are processing
     * @param response The HTTP response we are creating
     *
     * @exception Exception if business logic throws an exception
     */
    public ActionForward execute(ActionMapping mapping,
                 ActionForm form,
                 HttpServletRequest request,
                 HttpServletResponse response)
    throws Exception {

    // Extract attributes we will need
    HttpSession session = request.getSession();
    User user = (User) session.getAttribute(Constants.USER_KEY);

    // Process this user logoff
    if (user != null) {
            if (log.isDebugEnabled()) {
                log.debug("LogoffAction: User '" + user.getUsername() +
                          "' logged off in session " + session.getId());
            }
    } else {
            if (log.isDebugEnabled()) {
                log.debug("LogoffActon: User logged off in session " +
                          session.getId());
            }
    }
    session.removeAttribute(Constants.SUBSCRIPTION_KEY);
    session.removeAttribute(Constants.USER_KEY);
    session.invalidate();

    // Forward control to the specified success URI
    return (mapping.findForward("success"));

    }


}
